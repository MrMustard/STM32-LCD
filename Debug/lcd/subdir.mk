################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcd/lcd.c 

OBJS += \
./lcd/lcd.o 

C_DEPS += \
./lcd/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
lcd/%.o lcd/%.su: ../lcd/%.c lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/el_gl/STM32CubeIDE/workspace_1.8.0/state machine pattern/lcd" -I"C:/Users/el_gl/STM32CubeIDE/workspace_1.8.0/state machine pattern/serial" -I"C:/Users/el_gl/STM32CubeIDE/workspace_1.8.0/state machine pattern/leds" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lcd

clean-lcd:
	-$(RM) ./lcd/lcd.d ./lcd/lcd.o ./lcd/lcd.su

.PHONY: clean-lcd

