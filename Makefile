all:
	g++ -Isrc/include -Lsrc/lib main.cpp game.cpp entity.cpp player.cpp -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image