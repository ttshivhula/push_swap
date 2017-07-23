/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 07:28:31 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/07/23 10:57:43 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct	s_arr
{
	int			*arr;
	int			clen;
	int			olen;
}				t_arr;

typedef struct	s_ars
{
	t_arr		ara;
	t_arr		arb;
}				t_ars;

typedef struct	s_ints
{
	int	i;
	int v;
	int	j;
	int	e;
	int a_s;
	int v_pos;
	int num;
	int len;
	int *n;
	int *v_p;
}				t_ints;

typedef struct	s_vars
{
	char	*ins;
	char	*line;
	char	*temp;
	char	**ins_s;
	char	**av;
	char	**av_s;
}				t_vars;

void			check_big(char **v, int c, t_ints *t_i);
void			init(t_ints *i);
int				ft_isdigit_str(char *str);
void			ft_puterror(char const *error);
void			ft_atoi_max(const char *nptr, int **r);
int				main(int argc, char **argv);
void			ft_s_pargs(t_ars *t_a, t_vars *t_v, t_ints *t_i);
void			ft_pargs(t_ars *t_a, t_vars *t_v, t_ints *t_i, int ac);
void			ft_instruct(t_vars *t_v, t_ints *t_i);
void			ft_arrcheck(t_arr *ara, t_arr *arb);
void			ft_instructor(t_ars *t_a, t_vars *t_v, t_ints *t_i);
void			ft_checker(t_arr *ara, t_arr *arb, char *instruct);
void			ft_sab(t_arr *array);
void			ft_pab(t_arr *ara, t_arr *arb);
void			ft_checkerb(t_arr *ara, t_arr *arb, char *instruct);
void			ft_rab(t_arr *array);
void			ft_rrab(t_arr *array);
int				ft_chk_line(char *line, int e);
void			ft_check(char *elem, t_ints *t_i, t_ars *t_a);
void			ft_free(t_ars *t_a, t_vars *t_v, t_ints *t_i);

#endif
