/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:09:13 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/04 17:09:13 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_array(int ac, char *av[], t_stacks *ary)
{
	int	i;

	i = 1;
	ary->a_size = 0;
	ary->b_size = 0;
	while (--ac)
	{
		if (ft_count_words(av[i], ' '))
			ary->a_size += ft_count_words(av[i], ' ');
		else
			ary->a_size++;
		i++;
	}
	ary->a = malloc(ary->a_size * (sizeof * ary->a));
	if (ary->a == NULL)
		mem_error_handle(ary, "Error\n");
	ary->b = malloc(ary->a_size * (sizeof * ary->b));
	if (ary->b == NULL)
		mem_error_handle(ary, "Error\n");
}

int	ft_atoi_list(const char *s, t_stacks *ary)
{
	long		res;
	int			i;
	int			sign;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(s) > 11)
			mem_error_handle(ary, "Error\n");
		if (!(s[i] >= '0' && s[i] <= '9'))
			mem_error_handle(ary, "Error\n");
		res = res * 10 + (s[i++] - '0');
	}
	return ((int)(res * sign));
}

void	fill_stack_a(t_stacks *ary)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = ft_split(ary->total_num, ' ');
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		ary->a[j] = ft_atoi_list(tmp[i], ary);
		if (ary->a[j] > 2147483647 || ary->a[j] < -2147483648)
			mem_error_handle(ary, "Error\n");
		free(tmp[i]);
		i++;
		j++;
	}
	free(tmp);
}

int	check_stack_a_dup(t_stacks *ary)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ary->a_size)
	{
		j = i + 1;
		while (j < ary->a_size)
		{
			if (ary->a[i] == ary->a[j])
			{
				mem_error_handle(ary, "Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	create_index_num(t_stacks *ary)
{
	int		i;
	int		j;
	int		k;
	int		*num_a;

	num_a = malloc(ary->a_size * sizeof(int));
	if (num_a == NULL)
		mem_error_handle(ary, "Error\n");
	i = -1;
	while (++i < ary->a_size)
	{
		k = 0;
		j = -1;
		while (++j < ary->a_size)
		{
			if (ary->a[i] > ary->a[j])
				k++;
		}
		num_a[i] = k;
	}
	i = ary->a_size;
	while (i--)
		ary->a[i] = num_a[i];
	free(num_a);
}
