all:
	gcc -o main src/main.c -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf && ./main