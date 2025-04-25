CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g
CFLAGS_GCOV = -Wall -Wextra -pedantic -O1 -fsanitize=address -fno-omit-frame-pointer -g --coverage
CFLAGS_DEBUG = -Wall -Wextra -pedantic -O0 -fsanitize=address -fno-omit-frame-pointer -g

SRC = src/*.c
TEST = tests/*.c

.PHONY: jogo
jogo:
	$(CC) $(CFLAGS) $(SRC) src/main/main.c -o jogo

.PHONY: jogogcov
jogogcov:
	mkdir -p coverage
	$(CC) $(CFLAGS_GCOV) $(SRC) src/main/main.c -o jogo
	find . -maxdepth 1 -name '*.gcno' -exec mv {} coverage/ \;
	./jogo
	find . -maxdepth 1 -name '*.gcda' -exec mv {} coverage/ \;

	cd coverage && \
	for f in *; do \
		if [ -f "$$f" ]; then \
			nome_corrigido=$$(echo "$$f" | cut -c6-); \
			mv "$$f" "$$nome_corrigido"; \
		fi; \
	done


	find src -name '*.c' | while read file; do \
		gcov -o coverage "$$file" > /dev/null; \
	done

	mv *.gcov coverage/

.PHONY: limparNomes
limparNomes:
	@echo "Limpando nomes dos ficheiros na pasta coverage/..."
	@cd coverage && \
	for f in *; do \
		if [ -f "$$f" ]; then \
			nome_corrigido=$$(echo "$$f" | cut -c6-); \
			mv "$$f" "$$nome_corrigido"; \
		fi; \
	done
	@echo "Renomeação concluída!"

.PHONY: coverageJogo
coverageJogo:
	mkdir -p coverage

	find src -name '*.c' | while read file; do \
		gcov -o coverage "$$file" > /dev/null; \
	done

	mv *.gcov coverage/

.PHONY: testar
testar:
	$(CC) $(CFLAGS) -lcunit $(SRC) $(TEST) tests/main/main.c -o testar

.PHONY: testargcov
testargcov:
	$(CC) $(CFLAGS_GCOV) -lcunit $(SRC) $(TEST) tests/main/main.c -o testar
	@find tests -name '*.gcno' -exec mv {} coverage/ \;


.PHONY: coverageTestar
coverageTestar:
	@mkdir -p coverage
	@rm -f coverage/tests_*.gcov

	# Gerar cobertura dos ficheiros em tests/
	@find tests -name '*.gcda' -exec mv {} coverage/ \;
	@find tests -name '*.c' | while read file; do \
		gcov -o coverage "$$file" > /dev/null && \
		mv "$$(basename $$file).gcov" coverage/; \
	done

clean:
	rm -f jogo testar debug lib/teste5.txt lib/history/teste5.txt
	rm -f ./*.gcno ./*.gcda
	rm -f coverage/*

.PHONY: debug
debug:
	$(CC) $(CFLAGS_DEBUG) $(SRC) src/main/main.c -o debug
	# Caminho para a pasta onde estão os ficheiros
