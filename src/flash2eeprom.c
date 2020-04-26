/*
 * flash2eeprom.c
 *
 *  Created on: Apr 26, 2020
 *      Author: Administrator
 */
#include "flash2eeprom.h"
#include "stdint.h"
#include "main.h"//导入库函数

#ifdef __GNUC__

//变量对齐宏定义（实现由编译器分配可读写的空闲flash页的关键）
#define ALIGN(n) __attribute((aligned (n)))

#else

#error "暂不支持此编译器"

#endif

static  uint8_t ALIGN(PAGE_SIZE) const eeprom[PAGE_SIZE*PAGE_COUNT]={} ;

void    Flash_EEPROM_Erase_ALL_PAGE()
{
FLASH_EraseInitTypeDef Flash_ROM;  //声明 FLASH_EraseInitTypeDef 结构体为 Flash_ROM
HAL_FLASH_Unlock();               //解锁Flash
Flash_ROM.TypeErase=FLASH_TYPEERASE_PAGES;//标明Flash执行页面只做擦除操作
Flash_ROM.PageAddress=(uint32_t)eeprom;
Flash_ROM.NbPages=PAGE_COUNT;
uint32_t PageError = 0;                    //设置PageError,如果出现错误这个变量会被设置为出错的FLASH地址
HAL_FLASHEx_Erase(&Flash_ROM, &PageError);  //调用擦除函数擦除
HAL_FLASH_Lock();                 //锁定Flash
FLASH_WaitForLastOperation(1000);
}

void    Flash_EEPROM_Erase_One_PAGE(uint32_t page_offset)//擦除一页,page_offset为页编号
{

if(page_offset >= PAGE_COUNT)
	return;

FLASH_EraseInitTypeDef Flash_ROM;  //声明 FLASH_EraseInitTypeDef 结构体为 Flash_ROM
HAL_FLASH_Unlock();               //解锁Flash
Flash_ROM.TypeErase=FLASH_TYPEERASE_PAGES;//标明Flash执行页面只做擦除操作
Flash_ROM.PageAddress=(uint32_t)eeprom+PAGE_SIZE*page_offset;
Flash_ROM.NbPages=1;
uint32_t PageError = 0;                    //设置PageError,如果出现错误这个变量会被设置为出错的FLASH地址
HAL_FLASHEx_Erase(&Flash_ROM, &PageError);  //调用擦除函数擦除
HAL_FLASH_Lock();                 //锁定Flash
FLASH_WaitForLastOperation(1000);
}

void    Flash_EEPROM_Program_Word(uint32_t Address,uint32_t Data)
{

if(Address*4<PAGE_SIZE*PAGE_COUNT)//地址在Flash_ROM定义的范围内
{
  HAL_FLASH_Unlock();               //解锁Flash
  FLASH_WaitForLastOperation(1000);
  HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,(uint32_t)eeprom+Address*4,Data);
  FLASH_WaitForLastOperation(1000);
  HAL_FLASH_Lock();                 //锁定Flash
  FLASH_WaitForLastOperation(1000);

}

}


uint32_t Flash_EEPROM_Read_Word(uint32_t Address)
{
if(Address*4<PAGE_SIZE*PAGE_COUNT)//地址在Flash_ROM定义的范围内
{
  return *((uint32_t *)((uint32_t)eeprom+Address*4));
}
return 0;
}
