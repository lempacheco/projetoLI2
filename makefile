CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g 
CFLAGS_GCOV = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g --coverage
CFLAGS_DEBUG = -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -g

SRC = src/*.c
TEST = tests/*.c

.PHONY: jogo
jogo:
	$(CC) $(CFLAGS) $(SRC) src/main/main.c -o jogo -lncurses -ltinfo

.PHONY: testar
testar:
	$(CC) $(CFLAGS) -lcunit $(SRC) $(TEST) tests/main/main.c -o testar -lncurses -ltinfo


gcov:
	make clean
	$(CC) $(CFLAGS_GCOV) -lcunit $(SRC) $(TEST) tests/main/main.c -o testar -lncurses -ltinfo
	find . -maxdepth 1 -name '*.gcno' -exec mv {} coverage/ \;
	./testar
	find . -maxdepth 1 -name '*.gcda' -exec mv {} coverage/ \;

	cd coverage && \
	for f in *; do \
		if [ -f "$$f" ]; then \
			nome_corrigido=$$(echo "$$f" | cut -c8-); \
			mv "$$f" "$$nome_corrigido"; \
		fi; \
	done


	find src -name '*.c' | while read file; do \
		gcov -f -o coverage "$$file" >> coverage/output; \
		printf '\n\n\n' >> coverage/output; \
	done

	mv *.gcov coverage/
	rm coverage/*.gcno coverage/*.gcda
clean:
	rm -f jogo testar debug lib/teste5.txt lib/history/teste5.txt
	rm -f ./*.gcno ./*.gcda
	rm -f coverage/*

.PHONY: debug
debug:
	$(CC) $(CFLAGS_DEBUG) -lcunit $(SRC) src/main/main.c -o debug -lncurses -ltinfo
