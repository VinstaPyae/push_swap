#include "push_swap.h"

int	is_array_sorted(t_stacks *ary)
{
	int	i;

	i = 0;
	while (i < ary->a_size - 1)
	{
		if (ary->a[i] > ary->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three_num(t_stacks *ary)
{
	if (ary->a[2] != 2)
	{
		if (ary->a[0] == 2)
			rotate(ary->a, ary->a_size, "up", "a");
		else
			rotate(ary->a, ary->a_size, "down", "a");
	}
	if (ary->a[0] > ary->a[1])
		swap("sa", ary->a, ary->a_size);
}

void	sort_four_five_num(t_stacks *ary)
{
	while (ary->b_size <= 1)
	{
		if (ary->a[0] == 0 || ary->a[0] == 1)
			push("pb", ary);
		else
			rotate(ary->a, ary->a_size, "up", "a");
	}
	if (ary->b[0] == 0)
		swap("sb", ary->b, ary->b_size);
	if (ary->a[2] != 4)
	{
		if (ary->a[0] == 4)
			rotate(ary->a, ary->a_size, "up", "a");
		else
			rotate(ary->a, ary->a_size, "down", "a");
	}
	if (ary->a[0] > ary->a[1])
		swap("sa", ary->a, ary->a_size);
	push("pa", ary);
	push("pa", ary);
}

void	radix_sort_b(t_stacks *ary, int b_size, int bit_size, int i)
{
	while (b_size-- && i <= bit_size && !is_array_sorted(ary))
	{
		if (((ary->b[0] >> i) & 1) == 0)
			rotate(ary->b, ary->b_size, "up", "b");
		else
			push("pa", ary);
	}
	if (is_array_sorted(ary))
		while (ary->b_size != 0)
			push("pa", ary);
}

void	radix_sort(t_stacks *ary)
{
	int	i;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = ary->a_size;
	while (size > 1 && bit_size++)
		size /= 2;
	i = -1;
	while (++i <= bit_size)
	{
		size = ary->a_size;
		while (size-- && !is_array_sorted(ary))
		{
			if (((ary->a[0] >> i) & 1) == 0)
				push("pb", ary);
			else
				rotate(ary->a, ary->a_size, "up", "a");
		}
		radix_sort_b(ary, ary->b_size, bit_size, i + 1);
	}
	while (ary->b_size != 0)
		push("pa", ary);
}