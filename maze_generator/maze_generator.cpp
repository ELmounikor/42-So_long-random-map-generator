#include "maze_generator.hpp"


size_t	wall_snap_point(size_t dist)
{
	size_t snap_point;

	snap_point = (rand() % (dist - 2)) + 1;
	while (snap_point < RES)
		snap_point = (rand() % (dist - 2)) + 1;
	return snap_point;
}

size_t	door_snap_point(size_t dist)
{
	size_t snap_point;

	snap_point = (rand() % dist);
	return snap_point;
}

void	draw_wall(std::vector<std::string> &map, s_cords wall_start, s_cords wall_end, s_cords door, int direction)
{
	int v_add = (direction == VER);
	int h_add = (direction == HOR);

	size_t dist = (direction == HOR) ? DIST(wall_start.x, wall_end.x): DIST(wall_start.y, wall_end.y);

	door.x = (direction == VER) ? wall_start.x: wall_start.x + door_snap_point(dist);
	door.y = (direction == HOR) ? wall_start.y: wall_start.y + door_snap_point(dist);

	if (map[wall_start.y - v_add][wall_start.x - h_add] == '3')
	{
		wall_start.x += h_add;
		wall_start.y += v_add;
	}
	for (; wall_start.x < wall_end.x && wall_start.y < wall_end.y; wall_start.x += h_add, wall_start.y += v_add){
		if (wall_start.x == door.x && wall_start.y == door.y)
			map[wall_start.y][wall_start.x] = '3';
		else
			map[wall_start.y][wall_start.x] = '1';
	}
	if (map[wall_start.y][wall_start.x] == '3')
		map[wall_start.y - v_add][wall_start.x - h_add] = '0';
}


void	recurs_devide(std::vector<std::string> &map, s_cords start, size_t length, size_t width)
{
	static int calles = 0;
	if (length - 1 <= RES && width - 1 <= RES)
		return ;

	static size_t seed_mod = 3;

	srand(time(NULL) + seed_mod);

	seed_mod = rand();


	int split_direction = (length > width) ? VER: HOR;
	if (length == width)
		split_direction = rand() % 2;

	size_t wall_x = (split_direction == VER) ? wall_snap_point(length): 0;
	size_t wall_y = (split_direction == HOR) ? wall_snap_point(width): 0;
	s_cords wall_start((start.x + wall_x), (start.y + wall_y));
	s_cords wall_end((start.x + length), (start.y + width));

	draw_wall(map, wall_start, wall_end, start, split_direction);

	calles++;

	size_t new_length = (split_direction == VER) ? wall_x: length;
	size_t new_width = (split_direction == HOR) ? wall_y: width;
	s_cords n_start(start.x, start.y);

	recurs_devide (map, n_start, new_length, new_width);

	new(&n_start) s_cords(((start.x + wall_x) + (split_direction == VER)), ((start.y + wall_y) + (split_direction == HOR)));
	new_length = (length - (n_start.x - start.x));
	new_width = (width - (n_start.y - start.y)) ;

	recurs_devide (map, n_start, new_length, new_width);
}

void	add_elements(size_t C, std::vector <std::string> &map, char **av, size_t length, size_t width, s_cords &p_cords)
{
		bool P = false;
		bool E = false;
		size_t x = 0;
		size_t y = 0;
		
		// adding coins
		while (C > 0){
			x = rand() % length;
			y = rand() % width;

			size_t trying = 10000;
			while (--trying && map[y][x] != '0'){
				x = rand() % length;
				y = rand() % width;
			}
			if (trying == 0 && map[y][x] != '0')
				break ;
			map[y][x] = 'C';
			C--;
		}

		//adding player
		while (P == false){
			x = rand() % length;
			y = rand() % width;

			while (map[y][x] != '0' && map[y][x] != '3' && map[y][x] != 'C'){
				x = rand() % length;
				y = rand() % width;
			}
			map[y][x] = 'P';
			p_cords.x = x;
			p_cords.y = y;
			P = true;
		}

		//adding exit
		while (E == false){
			x = rand() % length;
			y = rand() % width;

			while ((map[y][x] != '0' && map[y][x] != 'C') || (map[y][x + 1] == '3' || map[y][x - 1] == '3' || map[y + 1][x] == '3' || map[y - 1][x] == '3')){
				x = rand() % length;
				y = rand() % width;
			}
			map[y][x] = 'E';
			E = true;
		}
}

int main(int ac, char **av)
{
	if (ac == 5){
		size_t width = strtoul(av[WIDTH], NULL, 10);
		size_t length = strtoul(av[LENGTH], NULL, 10);

		std::vector <std::string> *tmp1 = new std::vector <std::string>(width, std::string(length, '1'));;
		std::vector <std::string> &map = *tmp1;
		std::ofstream output_file(std::string("maps/").append(av[FILE_NAME]), std::ios::out | std::ios::trunc);

		start :
		for (int i = 1; i < map.size() - 1; i++){
			for (int j = 1; j < map[i].size() - 1; j++){
				map[i][j] = '0';
			}
		}

		s_cords start(1, 1);
		recurs_devide(map, start, length - 2, width - 2);

		s_cords p_cords(0, 0);
		add_elements(strtoul(av[COINS_COUNT], NULL, 10), map, av, length, width, p_cords);
		
		std::vector<std::vector<nodes> > *tmp2 = new std::vector<std::vector<nodes> >(width, std::vector<nodes>(length, nodes('1', WHITE, 0)));
		std::vector<std::vector<nodes> > &bfs_map = *tmp2;
		size_t C = 0;
		for (int i = 0; i < map.size(); i++){
			for (int j = 0; j < map[i].size(); j++){
				if (map[i][j] == '1'){
					bfs_map[i][j].c = map[i][j];
					output_file << map[i][j];
				}
				if (map[i][j] == '0' || map[i][j] == '3' || map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				{
					if (map[i][j] == '3')
						map[i][j] = '0';
					if (map[i][j] == 'C')
						C++;
					bfs_map[i][j].c = map[i][j];
					output_file << map[i][j];
				}
			}
			if (i != map[i].size() - 1)
				output_file << std::endl;
		}
		output_file.close();

		std::vector<vst_element> vst_frst;
		vst_frst.push_back(vst_element('C', C));
		if (!bfs_search(bfs_map, p_cords, vst_frst, vst_element('E', 1)))
			goto start;
	}
	else
		std::cout << "USAGE : ./executable [length] [width] [nbr of coins] [file name]" << std::endl;
	return 0;
}