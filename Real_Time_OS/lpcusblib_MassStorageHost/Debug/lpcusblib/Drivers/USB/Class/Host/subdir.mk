################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lpcusblib/Drivers/USB/Class/Host/MassStorageClassHost.c 

OBJS += \
./lpcusblib/Drivers/USB/Class/Host/MassStorageClassHost.o 

C_DEPS += \
./lpcusblib/Drivers/USB/Class/Host/MassStorageClassHost.d 


# Each subdirectory must supply rules for building sources it contributes
lpcusblib/Drivers/USB/Class/Host/%.o: ../lpcusblib/Drivers/USB/Class/Host/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__LPC175X_6X__ -DUSB_HOST_ONLY -DCORE_M3 -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpc_chip_175x_6x/inc" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpc_board_nxp_lpcxpresso_1769/inc" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpcusblib_MassStorageHost/example/inc" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpcusblib_MassStorageHost/lpcusblib/Drivers/USB" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpcusblib_MassStorageHost/fatfs/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


