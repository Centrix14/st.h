CC = gcc
CFLAGS = -Wall -O0 -g -o
SRC = sample.c
OUT = sample

all:
	$(CC) $(CFLAGS) $(OUT) $(SRC)
