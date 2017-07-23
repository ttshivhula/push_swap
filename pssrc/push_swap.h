/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:22:37 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/22 12:15:17 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_swap
{
	int				nb;
	int				nb_elem;
	struct s_swap	*prev;
	struct s_swap	*next;
}					t_swap;

int					doubles(char **str);
int					push_back(t_swap **list, int nb);
int					usage(int argc, char **argv);
int					push_front(t_swap **list, int nb);
void				swap_two_first(t_swap **root, char c);
int					first_b_in_a(t_swap **root_a, t_swap **root_b);
int					first_a_in_b(t_swap **root_a, t_swap **root_b, int verbose);
void				swap_two(t_swap **root_a, t_swap **root_b);
void				rotate(t_swap **root, int verbose);
void				rotate_end(t_swap **root, int verbose);
int					init_roots(t_swap **root_a, t_swap **root_b);
void				free_list(t_swap *root);
int					is_sort(t_swap *root, int reverse);
int					is_good_param(char *str);

#endif
