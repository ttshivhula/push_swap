/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 07:27:16 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 10:58:15 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_big(char **v, int c, t_ints *t_i)
{
	int i;

	i = 1;
	while (i < c)
	{
		if (ft_atol(v[i]) > 2147483647)
			ft_puterror("Error");
		i++;
	}
	init(t_i);
}

int		ft_chk_line(char *line, int e)
{
	if (ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0 &&
		ft_strcmp(line, "ss") != 0 && ft_strcmp(line, "pa") != 0 &&
		ft_strcmp(line, "pb") != 0 && ft_strcmp(line, "ra") != 0 &&
		ft_strcmp(line, "rb") != 0 && ft_strcmp(line, "rr") != 0 &&
		ft_strcmp(line, "rra") != 0 && ft_strcmp(line, "rrb") != 0 &&
		ft_strcmp(line, "rrr") != 0 && ft_strcmp(line, "") != 0)
		return (-4);
	else
		return (e);
}

void	ft_check(char *elem, t_ints *t_i, t_ars *t_a)
{
	int i;

	i = 0;
	while (i < t_i->len && t_i->e == 0)
	{
		if (ft_isdigit(elem[i]) != 1 && elem[i] != '-')
			t_i->e = -1;
		i++;
	}
	if (t_i->e == 0)
	{
		ft_atoi_max(elem, &t_i->n);
		if (t_i->n != &t_i->num)
			t_i->e = -2;
	}
	i = -1;
	while (++i < t_i->j && t_i->e == 0)
	{
		if (t_a->ara.arr[i] == *t_i->n)
			t_i->e = -3;
	}
}

void	ft_free(t_ars *t_a, t_vars *t_v, t_ints *t_i)
{
	if (t_i->e == 1)
		ft_putendl("OK");
	else
	{
		if (t_i->e == -5)
			ft_puterror("Error");
		free(t_a->ara.arr);
		if (t_i->e == -1)
			ft_puterror("Error");
		if (t_i->e == -2)
			ft_puterror("Error");
		if (t_i->e == -3)
			ft_puterror("Error");
		if (t_v->ins != NULL)
			ft_strdel(&t_v->ins);
		if (t_i->e == -4)
			ft_puterror("Error");
		free(t_a->arb.arr);
	}
}
