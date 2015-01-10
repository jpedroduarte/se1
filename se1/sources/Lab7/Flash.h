#ifndef _FLASH_H_
#define _FLASH_H_

#include "LPC2xxx.h"
#include "LPC2106.h"

/*IAP_COMMAND_CODES*/
#define PREPARE_SECTORS_FOR_WRITE_OPERATION 50
#define COPY_RAM_TO_FLASH 51
#define ERASE_SECTORS 52
#define BLANCK_CHECK_SECTORS 53
#define READ_PART_ID 54
#define READ_BOOT_CODE_VERSION 55
#define COMPARE 56

IAP iap_entry;
iap_entry= (IAP) IAP_LOCATION;
//Calling IAP procedure: iap_entry(command,result);
/*IAP_RESULT_STATUS_CODES*/
# define IAP_CMD_SUCESS 0
# define IAP_INVALID_COMMAND 1
# define IAP_SRC_ADDR_ERROR 2
# define IAP_DST_ADDR_ERROR 3
# define IAP_SRC_ADDR_NOT_MAPPED 4
# define IAP_DST_ADDR_NOT_MAPPED 5
# define IAP_COUNT_ERROR 6
# define IAP_INVALID_SECTOR 7
# define IAP_SECTOR_NOT_BLANK 8
# define IAP_SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION 9
# define IAP_COMPARE_ERROR 10
# define IAP_BUSY 11

unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector);
/* Apaga o conteúdo de um sector, ou de múltiplos sectores, da FLASH. Para apagar
apenas um sector, deve usar-se o mesmo número de sector para os dois parâmetros. */
unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size);
/* Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. Pressupõe que os sectores envolvidos na
operação de escrita foram apagados previamente e que size não excede 4kB. */
unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size);
/* Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. */
unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size);
/* Compara o conteúdo do bloco de dados referenciado por srcAddr, de dimensão size
bytes, com o conteúdo do bloco de dados referenciado por dstAddr. */

#endif/* _FLASH_H_ */
