#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct Map {
	int width;
	int height;
	int iterations;
	char *instructions;
	char **canvas;
} Map;

void	putstr(char *str) {
	for (int i = 0; str[i]; i++)
		putchar(str[i]);
}

int		mapError() {
	putstr("Error: Map Error!\n");
	return (1);
}

int mapInit(Map **map, int argc, char *argv[]) {
	if (argc != 4)
		return (1);
	(*map)->width = atoi(argv[1]);
	(*map)->height = atoi(argv[2]);
	(*map)->iterations = atoi(argv[3]);
	(*map)->canvas = (char **)malloc(sizeof(char *) * (*map)->height);
	for (int y = 0; y < (*map)->height; y++) {
		(*map)->canvas[y] = (char *)malloc((*map)->width + 1);
		(*map)->canvas[y][(*map)->width] = '\0';
	}
	char *buffer = (char *)malloc(1024);
	int bufferLen = read(0, buffer, 1023);
	buffer[bufferLen] = '\0';
	(*map)->instructions = buffer;
	return (0);
}

void	write_instractions(Map **map) {
	int x = 0;
	int	y = 0;

}

int main(int argc, char *argv[]) {
	Map *map = (Map *)malloc(sizeof(Map));
	if (mapInit(&map, argc, argv))
		return (mapError());
	
	return (0);
}
