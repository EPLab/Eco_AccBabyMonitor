################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../epl_rf_en.c \
../main.c \
../usb_api.c \
../usb_standard_desc.c 

C_DEPS += \
./epl_rf_en.d \
./main.d \
./usb_api.d \
./usb_standard_desc.d 

RELS += \
./epl_rf_en.rel \
./main.rel \
./usb_api.rel \
./usb_standard_desc.rel 


# Each subdirectory must supply rules for building sources it contributes
%.rel: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: SDCC Compiler'
	sdcc -c -I"C:\Program Files\EPL_LIB\LU1_LIB\include" --model-large --xram-size $v0x800 --code-size $v0x4000 --xram-loc $v0x8000 -o"$@" "$<" && \
	echo -n $(@:%.rel=%.d) $(dir $@) > $(@:%.rel=%.d) && \
	sdcc -c -MM -I"C:\Program Files\EPL_LIB\LU1_LIB\include" --model-large --xram-size $v0x800 --code-size $v0x4000 --xram-loc $v0x8000  "$<" >> $(@:%.rel=%.d)
	@echo 'Finished building: $<'
	@echo ' '


