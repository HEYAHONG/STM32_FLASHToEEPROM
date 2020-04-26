################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/project_in_git/FlashToEEPROM/src/flash2eeprom.c 

OBJS += \
./src/flash2eeprom.o 

C_DEPS += \
./src/flash2eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
src/flash2eeprom.o: D:/project_in_git/FlashToEEPROM/src/flash2eeprom.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/project_in_git/FlashToEEPROM/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/flash2eeprom.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

