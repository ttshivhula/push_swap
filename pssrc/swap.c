/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:21:38 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/21 18:36:17 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		first_b_in_a(t_swap **root_a, t_swap **root_b)
{
	t_swap	*tmp;

	if ((push_front(root_a, (*root_b)->next->nb)) == -1)
		return (-1);
	tmp = (*root_b)->next;
	(*root_b)->next = (*root_b)->next->next;
	(*root_b)->nb_elem = (*root_b)->nb_elem - 1;
	free(tmp);
	return (0);
}

int		first_a_in_b(t_swap **root_a, t_swap **root_b, int verbose)
{
	t_swap	*tmp;

	if ((push_front(root_b, (*root_a)->next->nb)) == -1)
		return (-1);
	tmp = (*root_a)->next;
	(*root_a)->next = (*root_a)->next->next;
	(*root_a)->nb_elem = (*root_a)->nb_elem - 1;
	free(tmp);
	ft_putstr((verbose == 1) ? ("pb") : ("pb\n"));
	return (0);
}

void	rotate(t_swap **root, int verbose)
{
	(*root)->prev->next = (*root)->next;
	(*root)->next->prev = (*root)->prev;
	(*root)->prev = (*root)->next;
	(*root)->next = (*root)->prev->next;
	(*root)->prev->next = (*root);
	(*root)->next->prev = (*root);
	ft_putstr((verbose == 1) ? ("ra") : ("ra\n"));
}

void	rotate_end(t_swap **root, int verbose)
{
	(*root)->prev->next = (*root)->next;
	(*root)->next->prev = (*root)->prev;
	(*root)->next = (*root)->prev;
	(*root)->prev = (*root)->prev->prev;
	(*root)->prev->next = (*root);
	(*root)->next->prev = (*root);
	ft_putstr((verbose == 1) ? ("rra") : ("rra\n"));
}

int		is_sort(t_swap *root, int reverse)
{
	t_swap	*tmp;

	tmp = root->next->next;
	while (tmp != root)
	{
		if (reverse == 0 && tmp->prev->nb > tmp->nb)
			return (-1);
		else if (reverse == 1 && tmp->prev->nb < tmp->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
