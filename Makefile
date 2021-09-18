CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = sdl2-light.h sld2-ttf-light.h
SRC = main.c Modules/graphics.c Modules/world.c Modules/player.c
OBJ = $(SRC:%.c=%.o)

INC_TEST = Modules/world.h Modules/player.h
SRC_TEST = Tests/tests.c  Modules/world.c Modules/player.c
OBJ_TEST = $(SRC_TEST:%.c=%.o)

PROG = jeu

PROG_TEST = test

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

jeu: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

test: $(OBJ_TEST)
	gcc $(CFLAGS) $(OBJ_TEST) $(LDFLAGS) -o $@



doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html


