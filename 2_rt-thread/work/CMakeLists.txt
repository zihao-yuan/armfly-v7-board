CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_PROCESSOR cortex-m7)
#SET(CMAKE_VERBOSE_MAKEFILE ON)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(CMAKE_C_COMPILER "D:/1_tool_prog/16_env/env_released_1.2.0/env/tools/ConEmu/ConEmu/../../../tools/gnu_gcc/arm_gcc/mingw/bin/arm-none-eabi-gcc.exe")
SET(CMAKE_ASM_COMPILER "D:/1_tool_prog/16_env/env_released_1.2.0/env/tools/ConEmu/ConEmu/../../../tools/gnu_gcc/arm_gcc/mingw/bin/arm-none-eabi-gcc.exe")
SET(CMAKE_C_FLAGS " -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g -std=c99")
SET(CMAKE_ASM_FLAGS " -c -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -x assembler-with-cpp -Wa,-mimplicit-it=thumb  -gdwarf-2")
SET(CMAKE_C_COMPILER_WORKS TRUE)

SET(CMAKE_CXX_COMPILER "D:/1_tool_prog/16_env/env_released_1.2.0/env/tools/ConEmu/ConEmu/../../../tools/gnu_gcc/arm_gcc/mingw/bin/arm-none-eabi-g++.exe")
SET(CMAKE_CXX_FLAGS " -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g")
SET(CMAKE_CXX_COMPILER_WORKS TRUE)

SET(CMAKE_OBJCOPY "D:/1_tool_prog/16_env/env_released_1.2.0/env/tools/ConEmu/ConEmu/../../../tools/gnu_gcc/arm_gcc/mingw/bin/arm-none-eabi-objcopy.exe")
SET(CMAKE_SIZE "D:/1_tool_prog/16_env/env_released_1.2.0/env/tools/ConEmu/ConEmu/../../../tools/gnu_gcc/arm_gcc/mingw/bin/arm-none-eabi-size.exe")

SET(CMAKE_EXE_LINKER_FLAGS " -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Wl,--gc-sections,-Map=rtthread.map,-cref,-u,Reset_Handler -T ${CMAKE_SOURCE_DIR}/board/linker_scripts/link.lds")

SET(CMAKE_CXX_STANDARD 14)
PROJECT(rtthread C CXX ASM)
INCLUDE_DIRECTORIES(
	applications
	board/bsp/inc
	board/bsp
	rt-thread/components/libc/compilers/common/include
	rt-thread/components/libc/compilers/newlib
	rt-thread/libcpu/arm/common
	rt-thread/libcpu/arm/cortex-m7
	rt-thread/components/drivers/include
	board
	board/CubeMX_Config/Inc
	libraries/HAL_Drivers
	libraries/HAL_Drivers/config
	libraries/HAL_Drivers/CMSIS/Include
	rt-thread/components/finsh
	.
	rt-thread/include
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Inc
	libraries/STM32H7xx_HAL/CMSIS/Device/ST/STM32H7xx/Include
	rt-thread/components/libc/posix/io/poll
	rt-thread/components/libc/posix/io/stdio
	rt-thread/components/libc/posix/ipc
)

ADD_DEFINITIONS(
	-DRT_USING_LIBC
	-DRT_USING_NEWLIBC
	-DSTM32H743xx
	-DUSE_HAL_DRIVER
	-D_POSIX_C_SOURCE=1
	-D__RTTHREAD__
)

SET(PROJECT_SOURCES
	applications/main.c
	board/bsp/src/bsp_led.c
	board/bsp/src/bsp_fmc_io.c
	board/bsp/bsp.c
	rt-thread/components/libc/compilers/common/cctype.c
	rt-thread/components/libc/compilers/common/cstdio.c
	rt-thread/components/libc/compilers/common/cstdlib.c
	rt-thread/components/libc/compilers/common/cstring.c
	rt-thread/components/libc/compilers/common/ctime.c
	rt-thread/components/libc/compilers/common/cwchar.c
	rt-thread/components/libc/compilers/newlib/syscalls.c
	rt-thread/libcpu/arm/common/div0.c
	rt-thread/libcpu/arm/common/showmem.c
	rt-thread/libcpu/arm/cortex-m7/context_gcc.S
	rt-thread/libcpu/arm/cortex-m7/cpu_cache.c
	rt-thread/libcpu/arm/cortex-m7/cpuport.c
	rt-thread/components/drivers/ipc/completion.c
	rt-thread/components/drivers/ipc/dataqueue.c
	rt-thread/components/drivers/ipc/pipe.c
	rt-thread/components/drivers/ipc/ringblk_buf.c
	rt-thread/components/drivers/ipc/ringbuffer.c
	rt-thread/components/drivers/ipc/waitqueue.c
	rt-thread/components/drivers/ipc/workqueue.c
	rt-thread/components/drivers/misc/pin.c
	rt-thread/components/drivers/serial/serial.c
	board/CubeMX_Config/Src/stm32h7xx_hal_msp.c
	board/board.c
	libraries/STM32H7xx_HAL/CMSIS/Device/ST/STM32H7xx/Source/Templates/gcc/startup_stm32h743xx.s
	libraries/HAL_Drivers/drv_common.c
	libraries/HAL_Drivers/drv_gpio.c
	libraries/HAL_Drivers/drv_sdram.c
	libraries/HAL_Drivers/drv_usart.c
	rt-thread/components/finsh/shell.c
	rt-thread/components/finsh/msh.c
	rt-thread/components/finsh/msh_parse.c
	rt-thread/components/finsh/cmd.c
	rt-thread/src/clock.c
	rt-thread/src/components.c
	rt-thread/src/device.c
	rt-thread/src/idle.c
	rt-thread/src/ipc.c
	rt-thread/src/irq.c
	rt-thread/src/kservice.c
	rt-thread/src/mem.c
	rt-thread/src/mempool.c
	rt-thread/src/object.c
	rt-thread/src/scheduler.c
	rt-thread/src/thread.c
	rt-thread/src/timer.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sram.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cryp_ex.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cryp.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_usart.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_crc_ex.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_comp.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rng.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_crc.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cec.c
	libraries/STM32H7xx_HAL/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c
	libraries/STM32H7xx_HAL/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.c
)

LINK_DIRECTORIES(
)

LINK_LIBRARIES(
	c
	m
)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCES})
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD 
COMMAND ${CMAKE_OBJCOPY} -O binary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin COMMAND ${CMAKE_SIZE} ${CMAKE_PROJECT_NAME}.elf)