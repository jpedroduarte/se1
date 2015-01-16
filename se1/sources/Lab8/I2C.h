#ifndef _I2C_H_
#define _I2C_H_


/* Faz a iniciação do sistema para permitir o acesso ao controlador I2C. */
void I2C_Init(void);

/* Realiza uma transferência I2C com o periférico identificado pelo endereço addr,
ao ritmo freq kHz e envolvendo size bytes. O buffer data contém os dados recebidos
para transferências de leitura (read = 1) ou os dados a enviar nas transferências
de escrita (read = 0).
Os valores de retorno desta função correspondem aos valores do registo I2CSTAT do
controlador I2C. */
unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned int
size, int freq);


#endif
