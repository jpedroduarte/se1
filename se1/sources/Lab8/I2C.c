#include "I2C.h"
#include "GPIO.h"

#define I2C_PIN_MASK0 (0x0F0) /**< Mask for Pinsel0 to affect P0.2(SCL) and P0.3(SDA). */
#define I2C_PIN_SEL0  (0x050) /**< Value for Pinsel0 to config pins to operate in i2c mode. */

#define I2C_I2EN_FLAG	(0x040)  /** enable flag bit mask. */
#define I2C_STA_FLAG	(0x020)  /**start flag bit mask. */
#define I2C_STO_FLAG	(0x010)  /**stop flag bit mask. */
#define I2C_SI_FLAG		(0x08)   /**interrupt flag bit mask. */
#define I2C_AA_FLAG		(0x04)   /**Acknowledge flag bit mask. */
#define I2C_CLEAR_ALL_FLAGS	(I2C_I2EN_FLAG | I2C_STA_FLAG | I2C_SI_FLAG | I2C_AA_FLAG) /**< Combination of all flags mask.*/

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

void I2C_Init(void){
	LPC2106_PINSEL.PINSEL0 &= ~(I2C_PIN_MASK0);
	LPC2106_PINSEL.PINSEL0 |= I2C_PIN_SEL0;
	LPC2106_I2C.I2CONCLR = I2C_CLEAR_ALL_FLAGS;
}

unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned int size, int freq){

	unsigned int SCL;
	unsigned char status;
	void *inicialAddr = data;
	void *finalAddr = ((char*)data + size * sizeof(char));
	SCL = ((LPC2106_MAIN_OSC)/freq)/2; 
	I2C_Start(SCL);
	while(1){
		if((I2CONSET & I2C_SI_FLAG) == I2C_SI_FLAG){
			switch(I2C.I2STAT){
				case I2C_STATE_START:
				case I2C_STATE_REPEAT_START:
					setSlaveAddr(addr, read);
					I2C.I2CONCLR = I2C_STA_FLAG;
				case I2C_STATE_SLAVE_ADDRESS_READ_ACK:
					I2C.I2CONSET = I2C_AA_FLAG;
					I2C.I2CONCLR = I2C_SI_FLAG;
					break;
				case I2C_STATE_DATA_RECEIVED_ACK: 
					I2C_Read(data);
					data = ((char *)data) + sizeof(char);
					if(data == finalAddress){ //last byte.
						status = I2C.I2STAT;
						I2C.I2CONCLR = I2C_AA_FLAG | I2C_SI_FLAG;
						I2C.I2CONCLR = I2C_SI_FLAG;
						I2C_Stop();
						return status;
					}
					I2C.I2CONSET = I2C_AA_FLAG;
					I2C.I2CONCLR = I2C_SI_FLAG;
					break;
				case I2C_STATE_DATA_RECEIVED_NACK:
					I2C_Read(data);
					status = I2C.I2STAT;
					I2C_Stop();
					return status;
				case I2C_STATE_SLAVE_ADDRESS_WRITE_ACK:
					I2C_Write(data);
					data = ((char *)data) + sizeof(char);
					break;
				case I2C_STATE_SLAVE_DATA_ACK:
					if(data == finalAddress){ //last byte.
						status = I2C.I2STAT;
						I2C_Stop();
						return status;
					}
					I2C_Write(data);
					data = ((char *)data) + sizeof(char);
					break;
				case I2C_STATE_TRANSMITION_LOST: 
					I2C.I2CONSET = (I2C_STA_FLAG );
					I2C.I2CONCLR = I2C_SI_FLAG;
					break;
				default:
					case I2C_STATE_BUS_ERROR:
					status = I2C.I2STAT;
					I2C_Stop();
					return status;
			}	
		}
	}
}

void I2C_Start(int scl){
	I2SCLH = scl;
	I2SCLL = scl;
	I2CONCLR = I2C_CLEAR_ALL_FLAGS;
	I2CONSET = I2C_STA_FLAG | I2C_I2EN_FLAG;
}

void I2C_Stop(){
	I2CONCLR = I2C_STO_FLAG;
	I2CONSET = I2C_SI_FLAG;
}

void setSlaveAddr(unsigned char addr, int read){
	I2DAT = (addr<<1) || (read & 1);
}

void I2C_Write(void *data){
	memcpy(data, (void*)&I2DAT, sizeof(char));
	I2CONCLR = I2C_SI_FLAG;
}

void I2C_Read(void *data){
	memcpy((void*)&I2DAT, data, sizeof(char));
	I2CONCLR = I2C_SI_FLAG;
}

