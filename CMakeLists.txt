CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

SET(CMAKE_ASM_NASM_FLAGS "-f elf32")
SET(CMAKE_C_FLAGS "-m32 -ffreestanding -nostdlib -fno-stack-protector -fno-pic")
SET(ISO_PATH "${CMAKE_CURRENT_BINARY_DIR}/isodir")

PROJECT(SparkOS C ASM_NASM)

ADD_EXECUTABLE(spark
	source/boot.asm
	source/gdt.c
	
	source/kernel/kmain.c
	source/kernel/kpanic.c
	source/kernel/kprintf.c
	source/kernel/kstatus.c

	source/drivers/cpu.c
	source/drivers/vga.c
	source/drivers/terminal.c

	source/library/string.c
)

TARGET_INCLUDE_DIRECTORIES(spark PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

TARGET_LINK_OPTIONS(spark PRIVATE
	"-m32"
	"-T${CMAKE_CURRENT_SOURCE_DIR}/linker.ld"
	"-nostdlib"
	"-static"
	"-Wl,--no-warn-rwx-segments"
)

ADD_CUSTOM_COMMAND(
	OUTPUT spark.iso
	COMMAND ${CMAKE_COMMAND} -E rm -rf ${ISO_PATH}
	COMMAND ${CMAKE_COMMAND} -E make_directory ${ISO_PATH}/boot/grub
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:spark> ${ISO_PATH}/boot/spark.bin
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/grub.cfg ${ISO_PATH}/boot/grub/grub.cfg
    COMMAND grub-mkrescue -o spark.iso ${ISO_PATH}
    DEPENDS spark ${CMAKE_CURRENT_SOURCE_DIR}/grub.cfg
    COMMENT "generating bootable ISO image"
)

SET_TARGET_PROPERTIES(spark PROPERTIES LINKER_LANGUAGE C)
ADD_CUSTOM_TARGET(iso ALL DEPENDS spark.iso)