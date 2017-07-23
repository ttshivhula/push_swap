/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 07:26:48 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 10:32:39 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_ints	t_i;
	t_vars	t_v;
	t_ars	t_a;

	init(&t_i);
	if (argc >= 2)
	{
		t_v.ins = NULL;
		t_v.av = argv;
		if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
			ft_s_pargs(&t_a, &t_v, &t_i);
		else if (argc > 2)
			ft_pargs(&t_a, &t_v, &t_i, argc);
		else if (ft_isdigit_str(argv[1]) != 1)
			t_i.e = -5;
		while (t_i.e == 0 && get_next_line(0, &t_v.line))
		{
			ft_instruct(&t_v, &t_i);
			ft_strdel(&t_v.line);
		}
		if (t_i.e == 0)
			ft_instructor(&t_a, &t_v, &t_i);
		ft_free(&t_a, &t_v, &t_i);
	}
	return (0);
}

void	ft_s_pargs(t_ars *t_a, t_vars *t_v, t_ints *t_i)
{
	t_i->n = &t_i->a_s;
	t_i->v_p = &t_i->v_pos;
	t_v->av_s = ft_strsplitnum(t_v->av[1], ' ', t_i->n);
	t_i->n = &t_i->num;
	t_i->e = 0;
	t_i->i = 0;
	t_i->j = -1;
	t_i->num = t_i->a_s + t_i->v;
	t_a->ara.olen = t_i->num;
	t_a->ara.arr = (int*)ft_memalloc(sizeof(int) * t_a->ara.olen);
	while (++t_i->i <= t_i->a_s && t_i->e == 0)
	{
		if (t_i->i != t_i->v_pos)
		{
			t_i->len = ft_strlen(t_v->av_s[t_i->i]);
			ft_check(t_v->av_s[t_i->i], t_i, t_a);
			if (t_i->e == 0)
				t_a->ara.arr[++t_i->j] = ft_atoi(t_v->av_s[t_i->i]);
		}
	}
	t_i->i = -1;
	while (++t_i->i < t_i->a_s)
		ft_strdel(&t_v->av_s[t_i->i]);
	free(t_v->av_s);
}

void	ft_pargs(t_ars *t_a, t_vars *t_v, t_ints *t_i, int ac)
{
	t_i->num = ac - 1;
	t_i->v_p = &t_i->v_pos;
	t_i->n = &t_i->num;
	t_i->e = 0;
	t_i->i = 0;
	t_i->j = 0;
	t_i->num += t_i->v;
	t_a->ara.olen = t_i->num;
	t_a->ara.arr = (int*)ft_memalloc(sizeof(int) * t_a->ara.olen);
	while (++t_i->i < ac && t_i->e == 0)
	{
		if (t_i->i != t_i->v_pos)
		{
			t_i->len = ft_strlen(t_v->av[t_i->i]);
			ft_check(t_v->av[t_i->i], t_i, t_a);
			if (t_i->e == 0)
			{
				t_a->ara.arr[t_i->j] = ft_atoi(t_v->av[t_i->i]);
				t_i->j++;
			}
		}
	}
}

void	ft_instruct(t_vars *t_v, t_ints *t_i)
{
	t_v->temp = NULL;
	t_i->len = ft_strlen(t_v->line);
	if (t_v->ins != NULL)
		t_i->num = ft_strlen(t_v->ins);
	else
		t_i->num = 0;
	t_i->e = ft_chk_line(t_v->line, t_i->e);
	if (t_i->num != 0 && t_i->e == 0)
	{
		t_v->temp = (char*)ft_memalloc((sizeof(char) * t_i->num) + 1);
		ft_strcpy(t_v->temp, t_v->ins);
		ft_strdel(&t_v->ins);
	}
	t_v->ins = (char*)ft_memalloc(sizeof(char) * (t_i->num + t_i->len + 1));
	if (t_v->temp != NULL && t_i->e == 0)
	{
		ft_strcpy(t_v->ins, t_v->temp);
		ft_strcat(t_v->ins, ".");
		ft_strdel(&t_v->temp);
	}
	ft_strcat(t_v->ins, t_v->line);
}

void	ft_arrcheck(t_arr *ara, t_arr *arb)
{
	int	aarr;
	int	barr;
	int	i;

	aarr = 0;
	barr = 0;
	i = -1;
	while (++i <= arb->olen)
	{
		if (arb->arr[i] != 0)
			barr++;
	}
	i = 0;
	while (i < ara->olen - 1)
	{
		if (ara->arr[i] > ara->arr[i + 1])
			aarr++;
		i++;
	}
	if (arb->clen == 0 && ara->clen == ara->olen && barr == 0 && aarr == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
