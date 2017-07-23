/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:16:43 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 08:55:38 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap	*create_list(int nb)
{
	t_swap	*new;

	new = NULL;
	if ((new = (t_swap*)malloc(sizeof(*new))))
	{
		new->nb = nb;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

int				push_back(t_swap **root, int nb)
{
	t_swap	*new;
	t_swap	*tmp;

	tmp = *root;
	new = create_list(nb);
	if (new)
	{
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev->next = new;
		tmp->prev = new;
		(*root)->nb_elem = (*root)->nb_elem + 1;
		return (0);
	}
	return (-1);
}

int				push_front(t_swap **root, int nb)
{
	t_swap	*new;
	t_swap	*tmp;

	tmp = *root;
	new = create_list(nb);
	if (new)
	{
		new->prev = tmp;
		new->next = tmp->next;
		tmp->next->prev = new;
		tmp->next = new;
		(*root)->nb_elem = (*root)->nb_elem + 1;
		return (0);
	}
	return (-1);
}

int				init_roots(t_swap **root_a, t_swap **root_b)
{
	(*root_a) = (t_swap*)malloc(sizeof(**root_a));
	(*root_a)->nb_elem = 0;
	(*root_a)->next = (*root_a);
	(*root_a)->prev = (*root_a);
	(*root_b) = (t_swap*)malloc(sizeof(**root_b));
	(*root_b)->nb_elem = 0;
	(*root_b)->next = (*root_b);
	(*root_b)->prev = (*root_b);
	return (0);
}

void			free_list(t_swap *root)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = root->next;
	while (tmp != root)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
}
