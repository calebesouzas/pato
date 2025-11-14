CC = gcc

round: src/*.o
	$(CC) *.o -o bin/round

src/%.o: *.c *.h
	$(CC) -c *.c -o *.o

clean:
	rm -rf src/*.o


