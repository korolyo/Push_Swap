#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdint.h>
# include <stdlib.h>

typedef struct s_dlist t_dlist;

struct	s_dlist
{
	uint64_t	value;
	uint64_t	score;
	t_dlist		*next;
	t_dlist		*prev;
};

#endif
