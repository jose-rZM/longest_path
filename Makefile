CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = main.c list.c map.c parser.c string_utils.c
OBJ = $(SRC:.c=.o)

TARGET = g_diam

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

.PHONY: all clean fclean