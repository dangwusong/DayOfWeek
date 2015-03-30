NAME = dayofweek

SRC_DIR = src
TEST_DIR = tests

SRC = $(wildcard $(SRC_DIR)/*.c)
TEST = $(wildcard $(TEST_DIR)/*.c)
INCLUDE = $(wildcard $(SRC_DIR)/*.h)

CC = gcc
WARNINGS = -Wall -Wextra -Werror
CFLAGS = $(WARNINGS) $(INCLUDE_DIR)

$(NAME): $(SRC) $(INCLUDE)
	$(CC) $(CFLAGS)$(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
