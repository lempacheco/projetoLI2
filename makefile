CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g

SRC = *.c 

jogo: $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o jogo

clean:
	rm -f *.o jogo
