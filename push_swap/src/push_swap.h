/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:06:43 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/04 17:06:43 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stacks
{
	char	*total_num;
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
}		t_stacks;

void		rotate(int *array, int size, char *dir, char *ab);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *ary);
void		radix_sort(t_stacks *ary);
void		fill_stack_a(t_stacks *ary);
void		create_index_num(t_stacks *ary);
void		create_array(int ac, char *av[], t_stacks *ary);
void		mem_error_handle(t_stacks *s, char *msg);
int			check_stack_a_dup(t_stacks *ary);
int			ft_atoi_list(const char *s, t_stacks *ary);
int			is_array_sorted(t_stacks *ary);

#endif