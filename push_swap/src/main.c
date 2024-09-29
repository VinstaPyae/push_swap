#include "push_swap.h"

void	mem_error_handle(t_stacks *ary, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (ary != NULL)
	{
		if (ary->a != NULL)
			free(ary->a);
		if (ary->b != NULL)
			free(ary->b);
		if (ary->total_num != NULL)
			free(ary->total_num);
		if (ary != NULL)
			free(ary);
	}
	exit(1);
}

static int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		return (1);
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || av[i][0] == ' ')
			return (1);
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j])) && av[i][j] != ' ' 
				&& av[i][j] != '-' && av[i][j] != '+')
				return (1);
			if ((av[i][j] == '-' || av[i][j] == '+') 
				&& (!av[i][j + 1] || av[i][j + 1] == ' '))
				return (1);
			j++;
		}
	}
	return (0);
}

static void	put_array_value(int ac, char *av[], t_stacks *ary)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i =  0;
	tmp2 = ft_strdup("");
	while (++i < ac && av[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, av[i]);
		if (tmp2)
			free(tmp2);
		if (i != ac - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	ary->total_num = ft_strdup(tmp);
	if (ary->total_num == NULL)
		mem_error_handle(ary, "Error\n");
	if (tmp)
		free(tmp);
}

int	main(int ac, char *av[])
{
	t_stacks	*ary;
	if (check_arg(ac, av))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	ary = malloc(sizeof(t_stacks));
	if (ary == NULL)
		return (0);
	create_array(ac, av, ary);
	put_array_value(ac, av, ary);
	fill_stack_a(ary);
	check_stack_a(ary, 0);
	create_index_num(ary);
	if (ary->a_size == 2 && ary->a[0] > ary->a[1])
		swap("sa", ary->a, ary->a_size);
	else if (ary->a_size == 3)
		sort_three_num(ary);
	else if (ary->a_size == 4 || ary->a_size == 5)
		sort_four_five_num(ary);
	else
		radix_sort(ary);
	check_stack_a(ary, 1);
	return (0);
}