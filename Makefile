OBJS = ./src/main.cpp

OBJ_NAME = bin/hello

all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)
