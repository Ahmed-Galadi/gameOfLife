#include "Canvas.hpp"
#include <iostream>
#include <unistd.h>

Canvas::Canvas(const std::string &penMoves, int width, int height) : drawer(Pen(penMoves, width, height)), width(width), height(height), grid(std::vector<std::string>(height)) {
	for (int y = 0; y < height; y++)
		grid[y] = std::string(width, DEAD);
}

int		Canvas::aliveNeibrsNum(int x, int y) {
	int		count = 0;

	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx == 0 && dy == 0) continue;
			int nx = x + dx;
			int	ny = y + dy;

			if (nx < 0 || ny < 0 || ny >= height || nx >= width)
				continue;
			if (grid[ny][nx] == LIVE)
				count++;
		}
	}
	return (count);
}

char	Canvas::life(char cell, int x, int y) {
	int aliveNeighbours = aliveNeibrsNum(x, y);

	if (cell == LIVE) {
		if (aliveNeighbours < 2 || aliveNeighbours > 3)
			return (DEAD);
		else if (aliveNeighbours == 2 || aliveNeighbours == 3)
			return (LIVE);
	} else if (cell == DEAD) {
		if (aliveNeighbours == 3)
			return (LIVE);
		else
			return (DEAD);
	}
	std::cerr << "ERROR: invalid cell!" << std::endl;
	exit(1);
}
void Canvas::printSimulation(const std::vector<std::string> &output) {
    // Clear screen and move cursor to top-left first
    std::cout << "\033[2J\033[H";
	std::cout << "Game Of Life\n";
    // Then print the current frame
    for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::string color;
			if (output[y][x] == DEAD)
				color = RED;
			if (output[y][x] == LIVE)
				color = GREEN;
			std::cout << color <<output[y][x] << RST ;
		}
		std::cout << std::endl;
	}
    
    std::cout << std::flush;
	usleep(500000);
}

void	Canvas::simulate(int iterations) {

	std::vector<std::string> output(height);

	for (int y = 0; y < height; y++) 
		output[y] = std::string(width, DEAD);
	drawer.draw(grid);
	if (!iterations)
		for (int y = 0; y < height; y++)
			std::cout << grid[y] << "\n";
	while (iterations--)
	{
		for (int y = 0; y < height; y++) 
			for (int x = 0; x < width; x++) 
				output[y][x] = life(grid[y][x], x, y);
		printSimulation(output);
		grid = output;
	}
}
