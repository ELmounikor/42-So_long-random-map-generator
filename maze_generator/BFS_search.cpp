#include "BFS_search.hpp"

bool	check_node(std::vector<std::vector<nodes> > &map, s_cords node, int index, size_t length, size_t width){
	std::pair<int, int> vel[4] = {std::make_pair(0,1),std::make_pair(1,0),std::make_pair(0,-1),std::make_pair(-1,0)};

	if (node.x + vel[index].first == length - 1 || node.y + vel[index].second == width - 1 || \
		node.x + vel[index].first < 1           || node.y + vel[index].second < 1 ||\
		map[node.y + vel[index].second][node.x + vel[index].first].c == '1' || \
		map[node.y + vel[index].second][node.x + vel[index].first].visited )
		return false;
	return true;
}

bool	check_vst_first(std::vector<vst_element> &vst_first){
	for (int i = 0; i < vst_first.size(); i++){
		if (vst_first[i].times != 0)
			return false;
	}
	return true;
}

bool	bfs_search(std::vector<std::vector<nodes> > &map, s_cords source, std::vector<vst_element> vst_first, vst_element vst_last){
	std::queue<s_cords> Q;
	std::pair<int, int> vel[4] = {std::make_pair(0,1),std::make_pair(1,0),std::make_pair(0,-1),std::make_pair(-1,0)};
	s_cords current(0, 0);

	Q.push(source);
	while (Q.size() != 0){
		current = Q.front();
		map[current.y][current.x].visited = true;
		map[current.y][current.x].color = BLACK; 
		Q.pop();
		if (vst_last.c == map[current.y][current.x].c){
			vst_last.times = 0;
			if (Q.empty()){
				if (check_vst_first(vst_first)){
					return true;
				}
				else{
					return false;
				}
			}
			Q.push(current);
			continue ;
		}
		for (int i = 0; i < 4; i++){
			if (check_node(map, current, i, map[0].size(), map.size())){
				map[current.y + vel[i].second][current.x + vel[i].first].color = GRAY;
				map[current.y + vel[i].second][current.x + vel[i].first].visited = true;
				for (int j = 0; j < vst_first.size(); j++){
					if (map[current.y + vel[i].second][current.x + vel[i].first].c == vst_first[j].c){
						vst_first[j].times--;
						break ;
					}
				}
				Q.push(s_cords(current.x + vel[i].first, current.y + vel[i].second));
			}
		}
	}
	if (vst_last.times == 0 && check_vst_first(vst_first))
		return true;
	else
		return false;
}
