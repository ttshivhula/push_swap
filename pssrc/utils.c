/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:37:39 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 08:53:30 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_good_param(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
		{
			ft_putstr("Error\n");
			return (-1);
		}
		i = i + 1;
	}
	return (0);
}

static int	double_finder(int *t, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (t[i] == t[j])
			{
				ft_putstr("Error\n");
				free(t);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free(t);
	return (0);
}

int			doubles(char **str)
{
	int i;
	int j;
	int ret;
	int *t;

	str++;
	i = 0;
	while (str[i])
		i++;
	t = malloc(sizeof(int) * (i + 1));
	j = 0;
	while (j < i)
	{
		t[j] = ft_atoi(str[j]);
		j++;
	}
	ret = double_finder(t, i);
	return (ret);
}
