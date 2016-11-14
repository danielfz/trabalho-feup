################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Feup.cpp \
../src/Pessoa.cpp \
../src/Test.cpp \
../src/Uc.cpp 

OBJS += \
./src/Feup.o \
./src/Pessoa.o \
./src/Test.o \
./src/Uc.o 

CPP_DEPS += \
./src/Feup.d \
./src/Pessoa.d \
./src/Test.d \
./src/Uc.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/danielf/workspace/InscricaoEstudantes/cute" -I"/home/danielf/workspace/InscricaoEstudantes/boost" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


