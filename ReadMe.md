# 简介

本库主要是用于将STM32 flash分配出来一部分用做EEPROM。

## 特点

* 分配由编译器决定，不用把用作EEPROM的地址写死
* 暂时只支持GCC。使用GCC作为编译器的IDE（如STM32CUBEIDE）理论上均支持。
* 依赖STM32 HAL库。

## 使用方法

1. 将src文件夹添加至STM32工程中
2. 根据当前单片机的数据手册修改flash2eeprom.h文件夹。
    - PAGE_SIZE 修改为当前单片机的flash页大小
    - PAGE_COUNT 根据需要修改要用做EEPROM的页数


# 当前状态

在以下单片机测试成功：
* STM32F103C8T6
