/*
 * flash2eeprom.h
 *
 *  Created on: Apr 26, 2020
 *      Author: Administrator
 */

#ifndef SRC_FLASH2EEPROM_H_
#define SRC_FLASH2EEPROM_H_
#include "stdint.h"
//定义页大小(需要与硬件一致)
#define PAGE_SIZE 1024

//定义用作EEPROM的flash页数量（需按照实际情况分配）
#define PAGE_COUNT 1

extern  void    Flash_EEPROM_Erase_ALL_PAGE();//擦除所有数据页

extern  void    Flash_EEPROM_Erase_One_PAGE(uint32_t page_offset);//擦除一页,page_offset为页编号

/*
在Flash内部的偏移对Flash写一个字(32位整数)。
Address为该字在Flash_EEPROM的偏移,其实际地址为Address*4。
Data为要写入的数据。
如果写入地址的值不为0xffffffff（擦除后的值），则需要擦除页。
*/
extern  void    Flash_EEPROM_Program_Word(uint32_t Address,uint32_t Data);

/*
读取1个字。
Address为该字在Flash_EEPROM的偏移,其实际地址为Address*4。
返回值为具体值,超出范围返回0.
*/
uint32_t Flash_EEPROM_Read_Word(uint32_t Address);



#endif /* SRC_FLASH2EEPROM_H_ */
