#pragma once

#include <vector>
#include <map>
#include <string>

class Pen {
	private:
		std::map<int, int> aliveCells;
	
	public:
		Pen(const std::string &penMov);

		void draw(std::vector<std::vector<bool>> &canvas);
};
