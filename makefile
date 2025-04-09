CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g

SRC = src/*.c
TEST = tests/*.c

.PHONY: jogo
jogo:
	$(CC) $(CFLAGS) $(SRC) src/main/main.c -o jogo

clean:
	rm -f jogo testar lib/teste5.txt

.PHONY: testar
testar:
	$(CC) $(CFLAGS) -lcunit $(SRC) $(TEST) tests/main/main.c -o testar
