################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/MassStorageHost.c \
../example/src/cr_startup_lpc175x_6x.c \
../example/src/sysinit.c 

OBJS += \
./example/src/MassStorageHost.o \
./example/src/cr_startup_lpc175x_6x.o \
./example/src/sysinit.o 

C_DEPS += \
./example/src/MassStorageHost.d \
./example/src/cr_startup_lpc175x_6x.d \
./example/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -D__LPC175X_6X__ -DUSB_HOST_ONLY -DCORE_M3 -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpc_chip_175x_6x/inc" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpc_board_nxp_lpcxpresso_1769/inc" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpcusblib_MassStorageHost/example/inc" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpcusblib_MassStorageHost/lpcusblib/Drivers/USB" -I"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpcusblib_MassStorageHost/fatfs/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


