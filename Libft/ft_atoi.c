/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:20:01 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/30 19:56:18 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

static void	check_char(char c)
{
	if (c < '0' || c > '9')
		ft_error();
}

int	my_atoi(char *str)
{
	unsigned long long int	n;
	unsigned int			i;
	int						sign;

	n = 0;
	i = 0;
	sign = 1;
	if (!str || !str[i])
		ft_error();
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	check_char(str[i]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		if ((sign == -1 && n > 2147483648) || (sign == 1 && n > 2147483647))
			ft_error();
		i++;
	}
	if (str[i])
		ft_error();
	return ((int) n * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main()
{
	char *s = "-9223372036854775809";
	//char *s = "1000000000000000001";
	printf("%d\n\n", ft_atoi(s));
	printf("%d", atoi(s));
}*/