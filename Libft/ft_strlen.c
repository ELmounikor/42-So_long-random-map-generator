/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:30:46 by mel-kora          #+#    #+#             */
/*   Updated: 2022/04/25 01:09:44 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s && s[length])
	{
		length++;
	}
	return (length);
}
/*
#include <stdio.h>
int main(void)
{
	char *s="mounia";

	printf("%d", ft_strlen(s));
}*/
