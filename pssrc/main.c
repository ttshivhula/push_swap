/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:11:40 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 08:50:25 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_min_max(t_swap *root, int reverse)
{
	int		min_max;
	t_swap	*tmp;
	int		i;
	int		place;

	i = 0;
	tmp = root->next;
	min_max = tmp->nb;
	place = 0;
	while (tmp != root)
	{
		if (reverse == 0 && tmp->nb < min_max)
		{
			min_max = tmp->nb;
			place = i;
		}
		else if (reverse == 1 && tmp->nb > min_max)
		{
			min_max = tmp->nb;
			place = i;
		}
		i = i + 1;
		tmp = tmp->next;
	}
	return (place);
}

static int	put_all_in_a(t_swap *root_a, t_swap *root_b, int verbose)
{
	while (root_b->next != root_b)
	{
		if ((first_b_in_a(&root_a, &root_b)) == -1)
			return (-1);
		if (verbose == 1)
			ft_putstr("pa");
		else
			ft_putstr((root_b->next != root_b) ? ("pa\n") : ("pa"));
	}
	free_list(root_a);
	free_list(root_b);
	return (0);
}

static int	sort_a(t_swap *root_a, t_swap *root_b, int verbose,
		int reverse)
{
	int		i;

	while (root_a->next != root_a)
	{
		i = search_min_max(root_a, reverse);
		if (i > (root_a->nb_elem / 2) && (root_a->nb_elem) != 1)
			while (i++ < root_a->nb_elem)
				rotate_end(&root_a, verbose);
		else
			while (i-- > 0)
				rotate(&root_a, verbose);
		if (root_b->nb_elem == 0 && is_sort(root_a, reverse) == 1)
			return (0);
		if ((first_a_in_b(&root_a, &root_b, verbose)) == -1)
			return (-1);
		if (root_b->nb_elem == 0 && is_sort(root_a, reverse) == 1)
			return (0);
	}
	return (0);
}

static int	get_arg(char **argv, t_swap **root_a)
{
	t_swap	*tmp;
	int		reverse;
	int		i;

	i = 1;
	reverse = 0;
	tmp = *root_a;
	while (argv[i])
	{
		if (is_good_param(argv[i]) == -1)
			return (-1);
		if (argv[i][1] != 'v' && argv[i][1] != 'r')
			if ((push_back(&tmp, ft_atoi(argv[i]))) == -1)
				return (-1);
		i = i + 1;
	}
	return (reverse);
}

int			main(int argc, char **argv)
{
	t_swap	*root_a;
	t_swap	*root_b;
	int		verbose;
	int		reverse;

	if (argc < 2)
		return (0);
	verbose = 0;
	if ((doubles(argv)) == -1)
		return (-1);
	if ((init_roots(&root_a, &root_b)) == -1)
		return (-1);
	if ((reverse = get_arg(argv, &root_a)) == -1)
		return (-1);
	if ((sort_a(root_a, root_b, verbose, reverse)) == -1)
		return (-1);
	put_all_in_a(root_a, root_b, verbose);
	return (0);
}
