#include "wall_carver.hpp"

std::vector<std::string>	create_grid(size_t length, size_t width, bool empty){
	std::vector <std::string> grid(width, std::string(length, '1'));
	if (empty){
		for (size_t y = 0; y < width; y++){
			for (size_t x = 0; x < length; x++){
				grid[y][x] = '0';
			}
		}
	}
	return grid;
}

void	backtracker_maze(std::vector <std::string> &map, frames start, size_t seed_mod)
{
	std::stack <frames> stack;
	std::vector <std::pair<int, int> > moves;
	moves.push_back(std::pair<int, int>(0, 2));
	moves.push_back(std::pair<int, int>(2, 0));
	moves.push_back(std::pair<int, int>(0, -2));
	moves.push_back(std::pair<int, int>(-2, 0));
	
	long nx;
	long ny;

	srand(time(NULL) + seed_mod);
	start.moves = moves;
	stack.push(start);
	while (!stack.empty())
	{
		frames &current = stack.top();
		map[current.y][current.x] = '0';
	
		size_t index = rand() % current.moves.size();
		nx = current.moves[index].first;
		ny = current.moves[index].second;
		long cur_x = current.x;
		long cur_y = current.y;
		current.moves.erase(current.moves.begin() + index);

		if (current.moves.size() == 0)
			stack.pop();
		if (cur_x + nx <= 0 || cur_y + ny <= 0 || cur_x + nx >= map[0].size() - 1 || cur_y + ny >= map.size() - 1 || map[cur_y + ny][cur_x + nx] == '0'){
			continue ;
		}
		map[cur_y + (ny / 2)][cur_x + (nx / 2)] = '0';
		stack.emplace(frames(cur_x + nx, cur_y + ny, moves));
	}
}
