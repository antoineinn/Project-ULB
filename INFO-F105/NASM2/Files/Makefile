

simulation_cell: ECA.cpp simulation_cell.o
			g++ -m32 ECA.cpp simulation_cell.o -o ECA

cipher.o: simulation_cell.asm
			nasm -f elf32 simulation_cell.asm -o simulation_cell.o 
