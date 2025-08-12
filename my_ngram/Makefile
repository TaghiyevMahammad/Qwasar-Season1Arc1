CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = my_ngram
OBJ = my_ngram.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ): my_ngram.c
	$(CC) $(CFLAGS) -c my_ngram.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
