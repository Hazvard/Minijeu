CC = g++
CFLAGS = -W -Wall -ansi -std=c99
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

EXEC = minijeu

SRC = main.cpp modules/Elise.cpp modules/entree.cpp modules/Carte.cpp modules/Menu.cpp modules/Liste.cpp modules/Score.cpp

OBJ = $(SRC:.c=.o)

INC_TEST = 
SRC_TEST = Tests/tests.c
OBJ_TEST = $(SRC_TEST:%.c=%.o)



all: $(EXEC)
minijeu: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -rf *.o *~
mrpropre: clean
	rm -rf $(EXEC)
	rm -rf test
	rm -rf $(OBJ_TEST)
test: $(OBJ_TEST)
	gcc $(CFLAGS) $(OBJ_TEST) $(LDFLAGS) -o $@