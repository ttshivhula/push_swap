/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 07:28:13 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 07:28:21 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checkerb(t_arr *ara, t_arr *arb, char *instruct)
{
	if (ft_strcmp(instruct, "ra") == 0)
		ft_rab(ara);
	if (ft_strcmp(instruct, "rb") == 0)
		ft_rab(arb);
	if (ft_strcmp(instruct, "rr") == 0)
	{
		ft_rab(ara);
		ft_rab(arb);
	}
	if (ft_strcmp(instruct, "rra") == 0)
		ft_rrab(ara);
	if (ft_strcmp(instruct, "rrb") == 0)
		ft_rrab(arb);
	if (ft_strcmp(instruct, "rrr") == 0)
	{
		ft_rrab(ara);
		ft_rrab(arb);
	}
}

void	ft_rab(t_arr *array)
{
	int i;
	int temp;

	i = 0;
	temp = array->arr[0];
	while (i < array->clen - 1)
	{
		array->arr[i] = array->arr[i + 1];
		i++;
	}
	array->arr[array->clen - 1] = temp;
}

void	ft_rrab(t_arr *array)
{
	int i;
	int len;
	int temp;

	i = 0;
	len = array->clen - 1;
	temp = array->arr[array->clen - 1];
	while (i < array->clen)
	{
		array->arr[len - i] = array->arr[(len - i) - 1];
		i++;
	}
	array->arr[0] = temp;
}
