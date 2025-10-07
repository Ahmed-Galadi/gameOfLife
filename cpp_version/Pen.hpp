#pragma once

#include <vector>
#include <set>
#include <string>

class Pen {
	private:
		std::set<std::pair<int, int>> aliveCells;
		int width;
		int height;

		void	getAlivePos(int x, int y,bool isDown);
	public:
		Pen(const std::string &penMov, int width, int height);

		void draw(std::vector<std::string> &canvas);
};
