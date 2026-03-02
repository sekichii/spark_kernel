# Spark Kernel
A *32-bit x86-based* kernel that focuses on **clean structure** and a robust, **modern building system**.

# Architecture, features
- Fully Multiboot 2 compliant
- i686 (32-bit x86) architecture
- CMake + Make building system
- Microkernel design philosophy

# Development roadmap
- [X] Multiboot header
- [X] Modern CMake integration
- [X] Basic VGA text-mode driver
- [X] `kprintf` coroutine
- [ ] CPUID implementation
- [ ] GDT/IDT implementation

# Prerequisites
- You'll need an `i686-elf`-capable cross-compiler
- You'll also need `nasm` for the assembly bits

# Building
```shell
# clone the github repository
git clone https://github.com/sekichii/spark_kernel.git
cd spark_kernel

# set the build directory up
mkdir build
cd build

# configure cmake, and build the binary
cmake ..
cmake --build .
```

The build system outputs both the bare binary for the kernel, and a fully bootable `.iso` file inside the build directory, that uses the GRUB bootloader.

# Booting 
### QEMU
```shell
# booting the iso
qemu-system-i386 -cdrom spark_kernel.iso -boot d

# booting the kernel (uses qemu's built-in bootloader)
qemu-system-i386 -kernel spark_kernel.bin
```
### VirtualBox
Add the .iso file as an Optical Drive via a PIIX4 controller. NOTE: since this is a 32-bit kernel, you'll have to set the OS Version to: "Other/Unknown", not "Other/Unknown 64-bit", otherwise it won't boot.

### Bare-Metal
Not tested, but it will likely work, if flashed on a bootable media device.