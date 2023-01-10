CC = clang++

OBJS_FILE = build/build_files.conf

OBJS := main.cpp $(shell cat $(OBJS_FILE))

C_FLAGS = -w

L_FLAGS = -lSDL2 -lSDL2_mixer -lSDL2_ttf -lSDL2_image

OBJ_OUT = main

build_config:
	bash make_config.sh

all:
	$(CC) $(C_FLAGS) $(OBJS) $(L_FLAGS) -o $(OBJ_OUT)
