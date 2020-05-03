OBJS	= Begin-game-tuto.o
SOURCE	= Begin-game-tuto.cpp
HEADER	= 
Library = sfml-app -lsfml-graphics -lsfml-window -lsfml-system
OUT	= game
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Begin-game-tuto.o: Begin-game-tuto.cpp
	$(CC) $(FLAGS) Begin-game-tuto.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)
