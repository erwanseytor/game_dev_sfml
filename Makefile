##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile	for	corewar
##

CC=g++
CFLAGS=-Wall -Wextra -iquote include
DEBUG_FLAGS=-g -fsanitize=address
LDFLAGS= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR=src
TEST_DIR=tests

SRC=$(wildcard $(SRC_DIR)/*.cpp \
	$(SRC_DIR)/classes/*.cpp $(SRC_DIR)/player/*.cpp)
TESTS=$(wildcard $(TEST_DIR)/*.c)
NAME=my_program
TRASH= *.gcno *.gcda test_runner *.info

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC)	-o	$(NAME)	$(SRC) $(CFLAGS) $(LDFLAGS)

test_run: $(TESTS)
	@$(CC) $(CFLAGS) -o test_runner $^ $(LDFLAGS)
	@./test_runner
	@gcovr --exclude tests/

debug:	$(SRC)
	@$(CC)	-o	$(NAME)	$(SRC) $(DEBUG_FLAGS) $(CFLAGS)

coverage: test
	@lcov -c -d . -o coverage.info
	@lcov --ignore-errors unused -r \
	coverage.info '/usr/*' '/opt/*' -o coverage.info
	@genhtml coverage.info --output-directory out
	@rm -rf out

style:
	@coding-style.sh . .
	@clear
	@echo "\033[35m===============================\033[0m"
	@echo "\033[32mCoding style errors :\033[0m\n\n"
	@cat coding-style-reports.log
	@echo "\n\033[35m===============================\033[0m"
	@rm -f *.log

clean:
	@$(RM)	$(OBJ)

fclean:	clean
	@$(RM)	$(NAME)	$(TRASH)

re:	fclean	all

.PHONY:	all	clean	fclean	re
