################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Clock.c \
../DIO.c \
../Interrupt.c \
../LCD.c \
../Schedular.c \
../Timer.c \
../main.c 

OBJS += \
./Clock.o \
./DIO.o \
./Interrupt.o \
./LCD.o \
./Schedular.o \
./Timer.o \
./main.o 

C_DEPS += \
./Clock.d \
./DIO.d \
./Interrupt.d \
./LCD.d \
./Schedular.d \
./Timer.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


