#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_stacks
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
	char	*total_num;
}		t_stacks;

void		rotate(int *array, int size, char *dir, char *ab);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *ary);
void		sort_three_num(t_stacks *ary);
void		sort_four_five_num(t_stacks *ary);
void		radix_sort(t_stacks *ary);
void		fill_stack_a(t_stacks *ary);
void		create_index_num(t_stacks *ary);
void		create_array(int ac, char *av[], t_stacks *ary);
void		mem_error_handle(t_stacks *s, char *msg);
void		check_stack_a(t_stacks *ary, int i);
int		ft_atoi_list(const char *s, t_stacks *ary);
int		is_array_sorted(t_stacks *ary);

#endif