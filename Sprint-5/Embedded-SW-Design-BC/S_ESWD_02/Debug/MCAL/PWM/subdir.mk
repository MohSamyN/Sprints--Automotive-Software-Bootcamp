################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/PWM/PWM.c \
../MCAL/PWM/PWM_Cfg.c 

OBJS += \
./MCAL/PWM/PWM.o \
./MCAL/PWM/PWM_Cfg.o 

C_DEPS += \
./MCAL/PWM/PWM.d \
./MCAL/PWM/PWM_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/PWM/%.o: ../MCAL/PWM/%.c MCAL/PWM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\APP\CarControl" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\APP\DisplayDistance" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\APP\GetDistance" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\APP\HBridgeControl" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\ECUAL\HBridge" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\ECUAL\LCD" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\ECUAL\SW_ICU" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\ECUAL\Ultrasonic" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\LIB" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\MCAL" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\MCAL\DIO" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\MCAL\EX_INT" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\MCAL\PWM" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\MCAL\Timer" -I"C:\Users\Mohamed Samy\eclipse-workspace\AutoCar3\Services\TDelay" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


