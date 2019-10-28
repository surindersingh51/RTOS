################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lpcusblib/Drivers/USB/Core/HCD/OHCI/subdir.mk
-include lpcusblib/Drivers/USB/Core/HCD/subdir.mk
-include lpcusblib/Drivers/USB/Core/HAL/LPC17XX/subdir.mk
-include lpcusblib/Drivers/USB/Core/subdir.mk
-include lpcusblib/Drivers/USB/Class/Host/subdir.mk
-include lpcusblib/Drivers/USB/Class/Common/subdir.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: lpcusblib_KeyboardHost.axf

# Tool invocations
lpcusblib_KeyboardHost.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpc_chip_175x_6x/Debug" -L"/home/devil/study_work/RTOS/lambton/2019/fall/ese3025/Real_Time_OS/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="lpcusblib_KeyboardHost.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "lpcusblib_KeyboardHost_Debug.ld" -o "lpcusblib_KeyboardHost.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) lpcusblib_KeyboardHost.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "lpcusblib_KeyboardHost.axf"; # arm-none-eabi-objcopy -v -O binary "lpcusblib_KeyboardHost.axf" "lpcusblib_KeyboardHost.bin" ; # checksum -p LPC1769 -d "lpcusblib_KeyboardHost.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
