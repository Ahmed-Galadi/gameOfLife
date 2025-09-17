#include "Canvas.hpp"

Canvas::Canvas(const std::string &penMoves, int width, int height) : drawer(Pen(penMoves)), width(width), height(height) {
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			grid[y].push_back(false);
}

void	Canvas::simulate(int iterations) {

}
