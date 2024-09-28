#include "push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_stacks *ary)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (ary->b_size <= 0)
			return;
		tmp = ary->b[0];
		ft_memmove(ary->a + 1, ary->a, sizeof(int) * ary->a_size);
		ary->a[0] = tmp;
		ary->b_size--;
		ft_memmove(ary->b, ary->b + 1, sizeof(int) * ary->b_size);
		ary->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (ary->a_size <= 0)
			return ;
		tmp = ary->a[0];
		ft_memmove(ary->b + 1, ary->b, sizeof(int) * ary->b_size);
		ary->b[0] = tmp;
		ary->a_size--;
		ft_memmove(ary->a, ary->a + 1, sizeof(int) * ary->a_size);
		ary->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *array, int size, char *dir, char *ab)
{
	int	tmp;

	if (size < 0)
		return;
	if (ft_strncmp(dir, "up", 3) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(dir, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(ab, 1);
}