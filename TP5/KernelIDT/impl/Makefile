INC_PATH = include/
DIRECTIVES = -fno-builtin -nostartfiles -nostdlib -I $(INC_PATH)
FLAGS = -g -m32 -c

all:
	nasm -f aout -g loader.asm -o loader.o 
	nasm -f aout -g asm/interrupts.asm -o asm_interrupts.o
	nasm -f aout -g arch/keys.asm -o keys.o
	nasm -f aout -g syscall.asm -o syscall.o 

	gcc $(FLAGS) arch/handlers.c -o arch_handlers.o $(DIRECTIVES)
	gcc $(FLAGS) kernel.c -o kernel.o $(DIRECTIVES) 
	gcc $(FLAGS) arch/keyboard_driver.c -o keyboard_driver.o $(DIRECTIVES)
	gcc $(FLAGS) arch/video_driver.c -o video_driver.o $(DIRECTIVES)
	gcc $(FLAGS) arch/strings.c -o strings.o $(DIRECTIVES)
	gcc $(FLAGS) arch/syscalls.c -o syscalls.o $(DIRECTIVES)
	
	ld -melf_i386 -T link.ld -o kernel.bin *.o
	rm *.o
	mcopy kernel.bin y:/boot -o
clean:
	rm *.o
	rm kernel.bin
	
