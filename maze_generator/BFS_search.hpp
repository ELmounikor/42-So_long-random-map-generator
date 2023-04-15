#pragma once

# include <queue>
# include <iostream>
# include <string>

struct s_cords
{
	size_t x;
	size_t y;

	s_cords(size_t _x, size_t _y): x(_x), y(_y){}


	s_cords(s_cords const &copy): x(copy.x), y(copy.y){}

	s_cords &operator = (s_cords &assign){
		x = assign.x;
		y = assign.y;
		return *this;
	}
};

enum {
	WHITE,
	GRAY,
	BLACK,
};

struct vst_element
{
	char c;
	size_t times;

	vst_element(char _c, size_t _times):c(_c), times(_times){};
};


struct nodes{
	char c;
	int color;
	bool visited;
	size_t dist;
	std::vector<s_cords> path;

	nodes(char _c, int _color, size_t _dist): c(_c), color(_color), dist(_dist){};
	nodes(nodes const &copy): c(copy.c), color(copy.color), dist(copy.dist){
		new (&path) std::vector<s_cords>(copy.path);
	};

	nodes &operator = (nodes &assign){
		c = assign.c;
		color = assign.color;
		visited = assign.visited;
		dist = assign.dist;
		path = assign.path;

		return *this;
	}

};

bool	bfs_search(std::vector<std::vector<nodes> > &map, s_cords source, std::vector<vst_element> vst_first, vst_element vst_last);