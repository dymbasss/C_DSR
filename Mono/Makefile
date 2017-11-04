SRC = main.c
SRO = main.o

all: built run 

main.o: $(SRC)
	@gcc -c $(SRC)

built: $(SRO)
	@gcc $(SRO) -o main.out

run: main.out
	@./main.out


