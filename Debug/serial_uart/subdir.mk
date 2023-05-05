################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../serial_uart/serial_uart.c 

OBJS += \
./serial_uart/serial_uart.o 

C_DEPS += \
./serial_uart/serial_uart.d 


# Each subdirectory must supply rules for building sources it contributes
serial_uart/%.o serial_uart/%.su: ../serial_uart/%.c serial_uart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/el_gl/Desktop/EMBEDDED SYSTEMS STATE MACHINES & DATA STRUCTURES/plantilla/plantilla_state_machine/serial_uart" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-serial_uart

clean-serial_uart:
	-$(RM) ./serial_uart/serial_uart.d ./serial_uart/serial_uart.o ./serial_uart/serial_uart.su

.PHONY: clean-serial_uart

