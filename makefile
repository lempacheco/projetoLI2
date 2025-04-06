CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g

SRC = src/*.c

jogo:
	$(CC) $(CFLAGS) $(SRC) -o bin/jogo

clean:
	rm -f bin/jogo
