#pragma once

#include <vector>
#include <string>
#include "Pen.hpp"

class Canvas {
	private:
		int width;
		int height;
		std::vector<std::vector<bool>> grid;
		Pen							   drawer;
	public:
		Canvas(const std::string &penMoves, int width, int height);
		
		void simulate(int iterations);		
};
