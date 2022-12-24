CC = clang++

OBJS = main.cpp src/game.cpp src/texture.cpp src/timer.cpp

C_FLAGS = -w

L_FLAGS = -lSDL2 -lSDL2_mixer -lSDL2_ttf -lSDL2_image

OBJ_OUT = main


all:
	$(CC) $(C_FLAGS) $(OBJS) $(L_FLAGS) -o $(OBJ_OUT)
