/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 07:27:39 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 07:28:10 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_instructor(t_ars *t_a, t_vars *t_v, t_ints *t_i)
{
	t_a->ara.clen = t_a->ara.olen;
	t_a->arb.olen = 0;
	t_a->arb.clen = 0;
	t_i->i = -1;
	t_a->arb.arr = (int*)ft_memalloc(sizeof(int) * t_a->ara.olen);
	while (++t_i->i < t_a->ara.olen)
		t_a->arb.arr[t_i->i] = 0;
	if (t_v->ins != NULL)
	{
		t_v->ins_s = ft_strsplit(t_v->ins, '.');
		t_i->i = -1;
		while (t_v->ins_s[++t_i->i])
		{
			if (t_v->ins_s[t_i->i][0] == 'r')
				ft_checkerb(&t_a->ara, &t_a->arb, t_v->ins_s[t_i->i]);
			else
				ft_checker(&t_a->ara, &t_a->arb, t_v->ins_s[t_i->i]);
			ft_strdel(&t_v->ins_s[t_i->i]);
		}
		free(t_v->ins_s);
	}
	ft_arrcheck(&t_a->ara, &t_a->arb);
}

void	ft_checker(t_arr *ara, t_arr *arb, char *instruct)
{
	if (ft_strcmp(instruct, "sa") == 0)
		ft_sab(ara);
	if (ft_strcmp(instruct, "sb") == 0)
		ft_sab(arb);
	if (ft_strcmp(instruct, "ss") == 0)
	{
		ft_sab(ara);
		ft_sab(arb);
	}
	if (ft_strcmp(instruct, "pa") == 0)
		ft_pab(ara, arb);
	if (ft_strcmp(instruct, "pb") == 0)
		ft_pab(arb, ara);
}

void	ft_sab(t_arr *array)
{
	int temp;

	if (array->clen > 1)
	{
		temp = array->arr[0];
		array->arr[0] = array->arr[1];
		array->arr[1] = temp;
	}
}

void	ft_pab(t_arr *ara, t_arr *arb)
{
	int i;

	i = 0;
	if (arb->clen > 0)
	{
		while (i < ara->clen)
		{
			ara->arr[ara->clen - i] = ara->arr[(ara->clen - 1) - i];
			i++;
		}
		ara->arr[0] = arb->arr[0];
		i = 0;
		while (i < arb->clen - 1)
		{
			arb->arr[i] = arb->arr[i + 1];
			i++;
		}
		arb->arr[i] = 0;
		arb->clen = arb->clen - 1;
		ara->clen = ara->clen + 1;
	}
}
