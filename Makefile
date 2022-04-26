TARGET=bin2txt.exe
OBJ=main.o
CC=gcc
CFLAGS=-c -Wall -g

TARGET:$(OBJ)
	$(CC) $^ -o $(TARGET)

%.o:%c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	@rm -r *.o $(TARGET)
