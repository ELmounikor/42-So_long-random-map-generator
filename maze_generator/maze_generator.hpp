#ifndef MAZE_GENERATOR_HPP
#define MAZE_GENERATOR_HPP

# include <iostream>
# include <vector>
# include <string>
# include "stdlib.h"
# include "time.h"
# include <unistd.h>
# include <math.h>
# include <fstream>
# include "BFS_search.hpp"

enum {
	VER,
	HOR,
};

# define RES 2
# define DIST(x1,x2) ((x2) - (x1))

enum {
	LENGTH = 1,
	WIDTH,
	COINS_COUNT,
	FILE_NAME,
};

void	recurs_devide(std::vector<std::string> &map, s_cords start, size_t length, size_t width);

#endif