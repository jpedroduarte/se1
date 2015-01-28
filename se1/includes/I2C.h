/** @file I2C.h
*  I2C module header.
*/
#ifndef _I2C_H_
#define _I2C_H_

#include <string.h>


#define I2C_FREQ 100000
/**
* Faz a iniciação do sistema para permitir o acesso ao controlador I2C. 
*/
void I2C_Init(void);

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
unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned int size, int freq);

void I2C_Read(void *data);
void I2C_Write(void *data);
void setSlaveAddr(unsigned char addr, int read);
void I2C_Stop();
void I2C_Start(int scl);


#endif
