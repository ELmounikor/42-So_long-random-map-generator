#pragma once

# include "maze_generator.hpp"

struct frames{
	long x;
	long y;
	std::vector <std::pair<int, int> > moves;

	frames (long _x, long _y, std::vector <std::pair<int, int> > _moves): x(_x), y(_y), moves(_moves){};
	frames (frames const &copy): x(copy.x), y(copy.y), moves(copy.moves){};
};

void	backtracker_maze(std::vector <std::string> &map, frames start, size_t seed_mod);
std::vector<std::string>	create_grid(size_t length, size_t width, bool empty);