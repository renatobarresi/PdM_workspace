################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/UserAPI/src/API_uart.c \
../Drivers/UserAPI/src/Consola_API.c \
../Drivers/UserAPI/src/FSM_API.c \
../Drivers/UserAPI/src/RTC_API.c \
../Drivers/UserAPI/src/Station_API.c 

OBJS += \
./Drivers/UserAPI/src/API_uart.o \
./Drivers/UserAPI/src/Consola_API.o \
./Drivers/UserAPI/src/FSM_API.o \
./Drivers/UserAPI/src/RTC_API.o \
./Drivers/UserAPI/src/Station_API.o 

C_DEPS += \
./Drivers/UserAPI/src/API_uart.d \
./Drivers/UserAPI/src/Consola_API.d \
./Drivers/UserAPI/src/FSM_API.d \
./Drivers/UserAPI/src/RTC_API.d \
./Drivers/UserAPI/src/Station_API.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/UserAPI/src/%.o: ../Drivers/UserAPI/src/%.c Drivers/UserAPI/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"/home/renato/Proyectos/CESE_FIUBA/Programacion de microcontroladores/PdM_workspace/Trabajo_practico_pdM/Drivers/UserAPI/inc" -I"/home/renato/Proyectos/CESE_FIUBA/Programacion de microcontroladores/PdM_workspace/Trabajo_practico_pdM/Drivers/UserAPI" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

