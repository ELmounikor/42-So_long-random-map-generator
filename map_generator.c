/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:57:07 by mel-kora          #+#    #+#             */
/*   Updated: 2022/07/23 12:52:17 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/Libft.h"
#define	UP		-1
#define DOWN	1
#define RIGHT	1
#define LEFT	-1

int	check(char **map, char *set)
{
	int	flags[3];
	int	i;
	int	j;

	i = -1;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == set[ft_strlen(set) - 1])
				flags[0]++;
			else if (map[i][j] == set[3])
				flags[1]++;
			else if (map[i][j] == set[2])
				flags[2]++;
		}
	}
	if (flags[0] == 1 && flags[1] > 0 && flags[2] > 0)
		return (1);
	return (0);
}

void	freemap(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i] = NULL);
	free(map);
}


char	**map_generator(char *set, int nbrw, int nbcl, int nbofmonsters)
{
	char	**map;
	int		flag = 0;
	int		monster_count = 0;
	int		i;
	int		j;

	map = (char **) calloc ((nbrw + 1), sizeof (char *));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < nbrw)
	{
		map[i] = (char *) calloc(nbcl + 1, sizeof(char));
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			// needs to return because malloc faild
			return (NULL);
		}
		j = -1;
		while (++j < nbcl)
		{
			while ((i == 0 || i == nbrw - 1) && j < nbcl)
				map[i][j++] = set[0];
			if (j < nbcl)
			{
				if (j == 0 || j == nbcl - 1)
					map[i][j] = set[0];
				else
				{
					if (set[rand() % (ft_strlen(set) - flag)] == '1')
						map[i][j] = set[rand() % (ft_strlen(set) - flag)];
					if (map[i][j] == set[ft_strlen(set) - 1])
						flag++;
					else if (ft_strlen(set) == 6 && map[i][j] == set[ft_strlen(set) - 2])
					{
						monster_count++;
						if (monster_count >= nbofmonsters)
							flag++;
					}
				}
			}
		}
		map[i][j] = 0;
	}
	map[i] = 0;
	return (map);
}
// av = program setofcharacters="10CEP" length=nbofrows width=nbofcolumns
// or if you want monsters 
// av = program setofcharacters="10CEMP" length=nbofrows width=nbofcolumns nbofmonsters 

int	main(int ac, char **av)
{
	int		nbofrows;
	int		nbofcolumns;
	int		nbofmonsters = 0;
	char	**map;
	FILE	*file;

	if ((ac == 5 && ft_strlen(av[1]) == 5) || (ac == 6 && ft_strlen(av[1]) == 6))
	{
		nbofrows = my_atoi(av[2]);
		nbofcolumns = my_atoi(av[3]);
		if (nbofcolumns < 4 || nbofrows < 4)
			ft_error();
		if (ac == 6)
			nbofmonsters = my_atoi(av[4]);
		file = fopen(av[ac - 1], "wb");
		map = map_generator(av[1], nbofrows, nbofcolumns, nbofmonsters);
		if (!map)
			return (1);
		while (!check(map, av[1]))
		{
			freemap(map);
			map = map_generator(av[1], nbofrows, nbofcolumns, nbofmonsters);
		}
		nbofrows = -1;
		while (map[++nbofrows])
		{
			fputs(map[nbofrows], file);
			if (map[nbofrows + 1])
				fputc('\n', file);
		}
		fclose(file);
		ft_putendl_fd("New map is created successfully!", 1);
	}
	else
	    ft_error();
}
