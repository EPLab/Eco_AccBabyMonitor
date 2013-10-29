################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
all: test_LU1.ihex

# Tool invocations
test_LU1.ihex: $(RELS) $(USER_RELS)
	@echo 'Building target: $@'
	@echo 'Invoking: SDCC Linker'
	sdcc -L"C:\Program Files\EPL_LIB\LU1_LIB\lib" --model-large --code-size $v0x4000 --xram-loc $v0x8000 --xram-size $v0x800 -o "test_LU1.ihex" $(RELS) $(USER_RELS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(RELS)$(EXECUTABLES) test_LU1.ihex
	-@echo ' '

post-build:
	-python "C:\Program Files\EPL_LIB\LU1_LIB\utils\sort_hex.py"   "test_LU1.ihex"  ../Release/"test_LU1.hex"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
