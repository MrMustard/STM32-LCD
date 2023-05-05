################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../serial/serial.c 

OBJS += \
./serial/serial.o 

C_DEPS += \
./serial/serial.d 


# Each subdirectory must supply rules for building sources it contributes
serial/%.o serial/%.su: ../serial/%.c serial/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/el_gl/STM32CubeIDE/workspace_1.8.0/state machine pattern/lcd" -I"C:/Users/el_gl/STM32CubeIDE/workspace_1.8.0/state machine pattern/serial" -I"C:/Users/el_gl/STM32CubeIDE/workspace_1.8.0/state machine pattern/leds" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-serial

clean-serial:
	-$(RM) ./serial/serial.d ./serial/serial.o ./serial/serial.su

.PHONY: clean-serial

