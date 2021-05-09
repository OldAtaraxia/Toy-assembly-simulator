CFLAGS = -Wall -g -O2 -Werror -std=gnu99

EXE = program

SRC = ./src

CODE = ./src/memory/instruction.c ./src/memory/dram.c ./src/disk/code.c ./src/cpu/mmu.c ./src/main.c

.PHONY: rpogram
main:
	gcc $(CFLAGS) -I$(SRC) $(CODE) -o $(EXE)

run:
	./$(EXE)
