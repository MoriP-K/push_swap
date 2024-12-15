#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef SIZE
#  define SIZE 10
# endif

typedef struct s_stack
{
	int			len;
	int			stack[SIZE];
	// struct s_stack	*next;
}					t_stack;

#endif