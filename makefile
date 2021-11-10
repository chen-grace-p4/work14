all: work14.o
	gcc -o work14 work14.o
work14.o: work14.c
	gcc -c work14.c
run:
	./work14
clean:
	rm *.o
	rm work14
	rm exit.txt
