/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:10:04 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/31 22:20:30 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* ordinary libft functions */
int		ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
int		my_atoi(char *s);
void	ft_error(void);
#endif
