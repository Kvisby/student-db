CC = gcc
BIN = student_db

student_db: main.c inout.c common.h file.c
	$(CC) main.c inout.c file.c -o $@

clean:
	rm -f *.o student_db data.bin

