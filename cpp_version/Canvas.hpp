#pragma once

#include <vector>
#include <string>
#include "Pen.hpp"

#define LIVE 'O'
#define DEAD '.'
#define RED "\e[31m"
#define GREEN "\e[32m"
#define RST	"\e[0m"

class Canvas {
	private:
		int width;
		int height;
		std::vector<std::string> grid;
		Pen						 drawer;
		
		void printSimulation(const std::vector<std::string> &output);
		int		aliveNeibrsNum(int x, int y);
		char	life(char cell, int x, int y);
	public:
		Canvas(const std::string &penMoves, int width, int height);
		
		void simulate(int iterations);		
};
