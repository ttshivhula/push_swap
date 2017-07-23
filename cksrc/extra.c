/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:01:24 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 09:42:59 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_isdigit_str(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_puterror(char const *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

void	ft_atoi_max(const char *nptr, int **r)
{
	int					counter;
	unsigned long long	done;
	int					flag;

	done = 0;
	counter = 0;
	flag = 0;
	if (nptr[0] == '-')
		flag++;
	while (nptr[counter] != '\0')
	{
		if (nptr[counter] > 47 && nptr[counter] < 58)
			done = ((done * 10) + nptr[counter]) - '0';
		counter++;
	}
	if (done / 4294967296 < 1)
	{
		if (flag == 1)
			done = done * -1;
		**r = (int)done;
	}
	else
		*r = NULL;
}

void	ft_putnendl(int n)
{
	ft_putnbr(n);
	write(1, "\n", 1);
}
