

cipher: print.cpp cipher.o
			g++ -m32 print.cpp cipher.o -o cipher

cipher.o: cipher.asm
			nasm -f elf32 cipher.asm -o cipher.o 
