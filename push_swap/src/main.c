#include "push_swap.h"

void	mem_error_handle(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->total_num != NULL)
			free(s->total_num);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

void	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		mem_error_handle(NULL, "");
}

int	main(int ac, char *av[])
{
	t_stacks	*s;
	validate_argument(ac, av);
	s = malloc(sizeof(t_stacks));
	if (s == NULL)
		return (0);
	creat_stacks(ac, av, s);
}