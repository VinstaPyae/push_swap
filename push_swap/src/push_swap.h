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

#endif