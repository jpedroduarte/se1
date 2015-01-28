/** @file I2C.c
*  I2C module .
*/
#include "/home/user/Desktop/host-se1/se1/includes/I2C.h"
#include "/home/user/Desktop/host-se1/se1/includes/GPIO.h"
#include "/home/user/Desktop/host-se1/se1/includes/LPC2xxx.h"
#include "/home/user/Desktop/host-se1/se1/includes/LPC2106.h"

/** 
* Mascara para o Pinsel0 afectar o P0.2(SCL) e o P0.3(SDA). 
*/
#define I2C_PIN_MASK0 (0x0F0) 

/**
* Valor para o Pinsel0 para configurar os pinos para a comunicação em i2c
*/
#define I2C_PIN_SEL0  (0x050) 

/**
* Valores das Flags do I2CONSET
*/
#define I2C_I2EN_FLAG	(0x040)  
#define I2C_STA_FLAG	(0x020)  
#define I2C_STO_FLAG	(0x010) 
#define I2C_SI_FLAG		(0x08)  
#define I2C_AA_FLAG		(0x04)   
#define I2C_CLEAR_ALL_FLAGS	(I2C_I2EN_FLAG | I2C_STA_FLAG | I2C_SI_FLAG | I2C_AA_FLAG)

/**
* Valores dos estados possiveis em Master Mode para o I2C.I2STAT
*/
#define I2C_STATE_BUS_ERROR (0x00)
#define I2C_STATE_START (0x08)
#define I2C_STATE_REPEAT_START (0x10)
#define I2C_STATE_SLAVE_ADDRESS_WRITE_ACK (0x18)
#define I2C_STATE_SLAVE_ADDRESS_WRITE_NACK (0x20)
#define I2C_STATE_SLAVE_DATA_ACK (0x28)
#define I2C_STATE_SLAVE_DATA_NACK (0x30)
#define I2C_STATE_TRANSMITION_LOST (0x38)
#define I2C_STATE_SLAVE_ADDRESS_READ_ACK (0x40)
#define I2C_STATE_SLAVE_ADDRESS_READ_NACK (0x48)
#define I2C_STATE_DATA_RECEIVED_ACK (0x50)
#define I2C_STATE_DATA_RECEIVED_NACK (0x58)

/**
* Faz a iniciação do sistema para permitir o acesso ao controlador I2C. 
*/
void I2C_Init(void){
	LPC2106_PINSEL.PINSEL0 &= ~(I2C_PIN_MASK0);
	LPC2106_PINSEL.PINSEL0 |= I2C_PIN_SEL0;
	LPC2106_I2C.I2CONCLR = I2C_CLEAR_ALL_FLAGS;
}

/**
* Realiza uma transferência I2C com o periférico identificado pelo endereço addr,
* ao ritmo freq kHz e envolvendo size bytes.
* @param addr Endereço do Slave
* @param read Quando 1 efectua uma leitura, quando 0 efectua uma escrita
* @param data Contém os dados recebidos para transferências de leitura ou
* os dados a enviar nas transferências de escrita
* @param size tamanho em bytes da comunicação 
* @param freq Frequencia do SCL
* @return Correspondem aos valores do registo I2CSTAT do controlador I2C.
*/
unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned int size, int freq){
	unsigned res,res2;
	unsigned int SCL;
	
	unsigned char status;
	
	void *inicialAddr = data;
	
	void *finalAddress = ((char*)data + size * sizeof(char));
	
	SCL = ((LPC2106_PCLK)/freq)/2; 
	I2C_Start(SCL);
	while(1){
		res= LPC2106_I2C.I2CONSET;
		if((LPC2106_I2C.I2CONSET & I2C_SI_FLAG) == I2C_SI_FLAG){
			res2 = LPC2106_I2C.I2STAT;
			switch(LPC2106_I2C.I2STAT){
				case I2C_STATE_START:
				case I2C_STATE_REPEAT_START:
					setSlaveAddr(addr, read);
					LPC2106_I2C.I2CONCLR = I2C_STA_FLAG;
				case I2C_STATE_SLAVE_ADDRESS_READ_ACK:
					LPC2106_I2C.I2CONSET = I2C_AA_FLAG;
					LPC2106_I2C.I2CONCLR = I2C_SI_FLAG;
					break;
				case I2C_STATE_DATA_RECEIVED_ACK: 
					I2C_Read(data);
					data = ((char *)data) + sizeof(char);
					if(data == finalAddress){ //last byte.
						status = LPC2106_I2C.I2STAT;
						LPC2106_I2C.I2CONCLR = I2C_AA_FLAG | I2C_SI_FLAG;
						LPC2106_I2C.I2CONCLR = I2C_SI_FLAG;
						I2C_Stop();
						return status;
					}
					LPC2106_I2C.I2CONSET = I2C_AA_FLAG;
					LPC2106_I2C.I2CONCLR = I2C_SI_FLAG;
					break;
				case I2C_STATE_DATA_RECEIVED_NACK:
					I2C_Read(data);
					status = LPC2106_I2C.I2STAT;
					I2C_Stop();
					return status;
				case I2C_STATE_SLAVE_ADDRESS_WRITE_ACK:
					I2C_Write(data);
					data = ((char *)data) + sizeof(char);
					break;
				case I2C_STATE_SLAVE_DATA_ACK:
					if(data == finalAddress){ //last byte.
						status = LPC2106_I2C.I2STAT;
						I2C_Stop();
						return status;
					}
					I2C_Write(data);
					data = ((char *)data) + sizeof(char);
					break;
				case I2C_STATE_TRANSMITION_LOST: 
					LPC2106_I2C.I2CONSET = (I2C_STA_FLAG );
					LPC2106_I2C.I2CONCLR = I2C_SI_FLAG;
					break;
				default:
					case I2C_STATE_BUS_ERROR:
					status = LPC2106_I2C.I2STAT;
					I2C_Stop();
					return status;
			}	
		}
		else{
			int i =0;
		}
		
	}
}


/**
* Efectua a condição de start
*/
void I2C_Start(int scl){
	LPC2106_I2C.I2SCLH = scl;
	LPC2106_I2C.I2SCLL = scl;
	LPC2106_I2C.I2CONCLR = I2C_CLEAR_ALL_FLAGS;
	LPC2106_I2C.I2CONSET = I2C_I2EN_FLAG | I2C_STA_FLAG;
}

/**
* Efectua a condição de stop
*/
void I2C_Stop(){
	LPC2106_I2C.I2CONCLR = I2C_STO_FLAG;
	LPC2106_I2C.I2CONSET = I2C_SI_FLAG;
}

/**
* Afecta o endereço do periferico que se pretende comunicar
*/
void setSlaveAddr(unsigned char addr, int read){
	LPC2106_I2C.I2DAT = (addr) | (read & 1);
}

/**
* Faz a escrita para o periférico
*/
void I2C_Write(void *data){
	memcpy(data, (void*)&LPC2106_I2C.I2DAT, sizeof(char));
	LPC2106_I2C.I2CONCLR = I2C_SI_FLAG;
}

/**
* Faz a leitura da data devolovida pelo periférico
*/
void I2C_Read(void *data){
	memcpy((void*)&LPC2106_I2C.I2DAT, data, sizeof(char));
	LPC2106_I2C.I2CONCLR = I2C_SI_FLAG;
}

