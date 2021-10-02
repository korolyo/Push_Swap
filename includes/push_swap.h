#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdint.h>
# include <stdlib.h>

typedef struct	s_dlist
{
	uint_64t	value;
	uint_64t	score;
	t_dlist		*next;
	t_dlist		*prev;
}				t_dlist;

#endif
