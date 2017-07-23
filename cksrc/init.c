/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 08:36:44 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 09:39:41 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** When working with structures on mac
** the variables comes initialized to some
** garbage values, this fixes such problems
** on linux everything was fine though ;)
*/

void	init(t_ints *i)
{
	i->i = 0;
	i->v = 0;
	i->j = 0;
	i->e = 1;
	i->a_s = 0;
	i->num = 0;
	i->len = 0;
}
