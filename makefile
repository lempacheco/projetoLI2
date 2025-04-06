CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g

SRC = etapa1.c 

jogo: $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o jogo

debug:
	gcc -g -o prog main.c quad.c -lm

clean:
	rm -f *.o jogo
