#include "Pen.hpp"
#include <iostream>
#include "Canvas.hpp"

Pen::Pen(const std::string &penMov, int width, int height) : width(width), height(height) {
	int			x = 0;
	int			y = 0;
	bool		isDown = false;

	for (int i = 0; i < penMov.size(); i++) {
		switch(penMov[i]) {
			case 'd': x++; break;
			case 'a': x--; break;
			case 'w': y--; break;
			case 's': y++; break;
			case 'x': isDown = !isDown; break;
			default:
				std::cerr << "ERROR: invalid movement!\n";
            return;
		}
		getAlivePos(x, y, isDown);  // <-- mark after move/toggle
	}
}

void	Pen::getAlivePos(int x, int y, bool isDown) {
	if (!isDown)
		return ;
	if (x < 0 || y < 0 || y >= height || x >= width) return;
	aliveCells.insert(std::make_pair(x, y));
}

void	Pen::draw(std::vector<std::string> &canvas) {
	std::set<std::pair<int, int>>::iterator it = aliveCells.begin();

	for (; it != aliveCells.end(); it++)
		canvas[it->second][it->first] = LIVE;
}
