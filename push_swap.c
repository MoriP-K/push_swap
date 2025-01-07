/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:50:03 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/01/07 23:06:34 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

void	sa(int *a)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = a[i];
	a[i] = a[i + 1];
	a[i + 1] = tmp;
}

void	sb(int *b)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = b[i];
	b[i] = b[i + 1];
	b[i + 1] = tmp;
}

void	ss(int *a, int *b)
{
	sb(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;

	if (b->len == 0)
		return ;
	tmp = b->data[0];
	b->len--;
	i = 0;
	while (i < b->len)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	a->len++;
	i = 1;
	while (i < a->len)
	{
		a->data[a->len - i] = a->data[a->len - i - 1];
		i++;
	}
	a->data[0] = tmp;
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;

	if (a->len == 0)
		return ;
	tmp = a->data[0];
	a->len--;
	i = 0;
	while (i < a->len)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	b->len++;
	i = 1;
	while (i < b->len)
	{
		b->data[b->len - i] = b->data[b->len - i - 1];
		i++;
	}
	b->data[0] = tmp;
}

void	ra(t_stack *a)
{
	int	i;
	int	tmp;

	tmp = a->data[0];
	i = 1;
	while (i < a->len)
	{
		a->data[i - 1] = a->data[i];
		i++;
	}
	a->data[i - 1] = tmp;
}

void	rb(t_stack *b)
{
	int	i;
	int	tmp;

	tmp = b->data[0];
	i = 1;
	while (i < b->len)
	{
		b->data[i - 1] = b->data[i];
		i++;
	}
	b->data[i - 1] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
}

void	rra(t_stack *a)
{
	int	i;
	int	tmp;

	tmp = a->data[a->len - 1];
	i = 1;
	while (i < a->len)
	{
		a->data[a->len - i] = a->data[a->len - i - 1];
		i++;
	}
	a->data[0] = tmp;
}

void	rrb(t_stack *b)
{
	int	i;
	int	tmp;

	tmp = b->data[b->len - 1];
	i = 1;
	while (i < b->len)
	{
		b->data[b->len - i] = b->data[b->len - i - 1];
		i++;
	}
	b->data[0] = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	sort(int *compressed, t_stack *a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < a->len - 1)
	{
		j = 0;
		while (j < a->len - i - 1)
		{
			if (compressed[j] > compressed[j + 1])
				sa(&compressed[j]);
			j++;
		}
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_double(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->len)
	{
		j = i + 1;
		while (j < a->len)
		{
			if (a->data[i] == a->data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_memflow(int sign, long result, char **endptr, char *nptr)
{
	if (result > (LONG_MAX - (*nptr - '0')) / 10)
	{
		if (endptr)
			*endptr = (char *)nptr + 1;
		if (sign == -1)
			return (INT_MIN);
		return (INT_MAX);
	}
	return (0);
}

int	set_endptr(long result, char **endptr, char *nptr)
{
	*endptr = nptr;
	return (result);
}

long	ft_strtol(const char *nptr, char **endptr)
{
	size_t		i;
	int			sign;
	long		result;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -sign;
	result = 0;
	while (nptr[i] && ft_isdigit((int)nptr[i]))
	{
		if (ft_memflow(sign, result, endptr, (char *)&(nptr[i])))
			return (ft_memflow(sign, result, endptr, (char *)&(nptr[i])));
		result = result * 10 + (nptr[i++] - '0');
	}
	if (endptr)
		*endptr = (char *)&nptr[i];
	return (sign * result);
}

char	**set_arg(int ac, char **av, t_stack *a, int *is_alloated)
{
	char	**array;

	*is_alloated = 0;
	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		array = ft_split(av[1], ' ');
		if (!array)
			return (NULL);
		a->len = (int)ft_arrlen(array);
		*is_alloated = 1;
	}
	else
	{
		array = &av[1];
		a->len = ac - 1;
	}
	return (array);
}

int	ft_isint(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -sign;
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		result = result * 10 + sign * (nptr[i++] - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (0);
	}
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_int(long long num, char **array, char *endptr, int is_allocated)
{
	if (*endptr != '\0' || num < INT_MIN || num > INT_MAX)
	{
		if (is_allocated)
			free(array);
		return (0);
	}
	return (1);
}

int	validate_arg(int ac, char **av, t_stack *a)
{
	int			i;
	long long	num;
	int			is_allocated;
	char		*endptr;
	char		**array;

	array = set_arg(ac, av, a, &is_allocated);
	if (!array)
		return (0);
	i = 0;
	while (i < a->len)
	{
		if (!ft_isint(array[i]))
			return (0);
		endptr = NULL;
		num = ft_strtol(array[i], &endptr);
		if (!ft_int(num, array, endptr, is_allocated))
			return (0);
		a->data[i++] = (int)num;
	}
	if (is_allocated)
		free_array(array);
	if (check_double(a))
		return (0);
	return (1);
}

int	*numcpy(int *dest, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		dest[i] = a->data[i];
		i++;
	}
	return (dest);
}

int	assign_index(int *copmressed, int num, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (copmressed[i] == num)
			return (i);
		i++;
	}
	return (0);
}

void	compress_stack(t_stack *a)
{
	int	*compressed;
	int	i;

	compressed = malloc(sizeof(int) * a->len);
	if (!compressed)
		return ;
	compressed = numcpy(compressed, a);
	sort(compressed, a);
	i = 0;
	while (i < a->len)
	{
		a->data[i] = assign_index(compressed, a->data[i], a->len);
		i++;
	}
	free(compressed);
}

void	check_cmds(t_list *cmd_lists)
{
	t_list	*current;

	current = cmd_lists;
	while (current)
	{
		if (current->next != NULL
			&& ((current->data == RA && current->next->data == RB)
				|| (current->data == RB && current->next->data == RA)))
		{
			current->data = RR;
			current->next->data = NONE;
		}
		current = current->next;
	}
}

void	write_cmd(t_command cmd)
{
	if (cmd == SA)
		write(1, "sa\n", 3);
	else if (cmd == SB)
		write(1, "sb\n", 3);
	else if (cmd == SS)
		write(1, "ss\n", 3);
	else if (cmd == RA)
		write(1, "ra\n", 3);
	else if (cmd == RB)
		write(1, "rb\n", 3);
	else if (cmd == RR)
		write(1, "rr\n", 3);
	else if (cmd == RRA)
		write(1, "rra\n", 4);
	else if (cmd == RRB)
		write(1, "rrb\n", 4);
	else if (cmd == RRR)
		write(1, "rrr\n", 4);
	else if (cmd == PA)
		write(1, "pa\n", 3);
	else if (cmd == PB)
		write(1, "pb\n", 3);
}

void	print_cmds(t_list *cmd_lists)
{
	t_list		*current;
	t_command	cmd;

	current = cmd_lists;
	while (current)
	{
		check_cmds(cmd_lists);
		if (current->data == NONE)
			current = current->next;
		cmd = current->data;
		write_cmd(cmd);
		current = current->next;
	}
}

void	exec_swap(t_stack *a, t_stack *b, t_command cmd)
{
	if (cmd == SA)
		sa(&a->data[0]);
	else if (cmd == SB)
		sb(&b->data[0]);
	else if (cmd == SS)
		ss(&a->data[0], &b->data[0]);
}

void	exec_rotate(t_stack *a, t_stack *b, t_command cmd)
{
	if (cmd == RA)
		ra(a);
	else if (cmd == RB)
		rb(b);
	else if (cmd == RR)
		rr(a, b);
}

void	exec_reverse_rotate(t_stack *a, t_stack *b, t_command cmd)
{
	if (cmd == RRA)
		rra(a);
	else if (cmd == RRB)
		rrb(b);
	else if (cmd == RRR)
		rrr(a, b);
}

void	exec_push(t_stack *a, t_stack *b, t_command cmd)
{
	if (cmd == PA)
		pa(a, b);
	else if (cmd == PB)
		pb(a, b);
}

void	add_cmd(t_list **cmd_lists, t_command cmd)
{
	t_list	*node;

	node = ft_lstnew(cmd);
	if (!node)
		return ;
	ft_lstadd_back(cmd_lists, node);
}

void	exec_cmd(t_command cmd, t_stack *a, t_stack *b, t_list **cmd_lists)
{
	if (cmd == SA || cmd == SB || cmd == SS)
		exec_swap(a, b, cmd);
	else if (cmd == RA || cmd == RB || cmd == RR)
		exec_rotate(a, b, cmd);
	else if (cmd == RRA || cmd == RRB || cmd == RRR)
		exec_reverse_rotate(a, b, cmd);
	else if (cmd == PA || cmd == PB)
		exec_push(a, b, cmd);
	add_cmd(cmd_lists, cmd);
}

int	search_max_index(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = 0;
	index = 0;
	while (i < stack->len)
	{
		if (max < stack->data[i])
		{
			max = stack->data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	search_min_index(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack->data[0];
	index = 0;
	while (i < stack->len)
	{
		if (min > stack->data[i])
		{
			min = stack->data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	search_min_pb(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	int	min_index;

	min_index = search_min_index(a);
	if (min_index < a->len / 2)
	{
		while (min_index)
		{
			exec_cmd(RA, a, b, cmd_lists);
			min_index--;
		}
	}
	else
	{
		while (a->len > min_index)
		{
			exec_cmd(RRA, a, b, cmd_lists);
			min_index++;
		}
	}
	exec_cmd(PB, a, b, cmd_lists);
}

void	search_max_pa(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	int	max_index;

	max_index = search_max_index(b);
	if (max_index <= b->len / 2)
	{
		while (max_index)
		{
			exec_cmd(RB, a, b, cmd_lists);
			max_index--;
		}
	}
	else
	{
		while (b->len > max_index)
		{
			exec_cmd(RRB, a, b, cmd_lists);
			max_index++;
		}
	}
	exec_cmd(PA, a, b, cmd_lists);
}

void	sort_two(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	if (a->data[0] > a->data[1])
		exec_cmd(SA, a, b, cmd_lists);
}

void	sort_three(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	int	max_index;

	max_index = search_max_index(a);
	if (max_index == 0)
	{
		exec_cmd(RA, a, b, cmd_lists);
		if (a->data[0] > a->data[1])
			exec_cmd(SA, a, b, cmd_lists);
	}
	else if (max_index == 1)
	{
		exec_cmd(RRA, a, b, cmd_lists);
		if (a->data[0] > a->data[1])
			exec_cmd(SA, a, b, cmd_lists);
	}
	else if (max_index == 2 && a->data[0] > a->data[1])
		exec_cmd(SA, a, b, cmd_lists);
}

void	sort_four(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	search_min_pb(a, b, cmd_lists);
	sort_three(a, b, cmd_lists);
	exec_cmd(PA, a, b, cmd_lists);
}

void	sort_more_than_five(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	while (a->len > 3)
		search_min_pb(a, b, cmd_lists);
	sort_three(a, b, cmd_lists);
	while (b->len)
		exec_cmd(PA, a, b, cmd_lists);
}

int	count_range(t_stack *a, int min, int max)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < a->len)
	{
		if (min <= a->data[i] && a->data[i] < max)
			count++;
		i++;
	}
	return (count);
}

int	is_in_range(int num, int min, int max)
{
	return (min <= num && num < max);
}

int	split_chunk_size(int len)
{
	int	chunk_size;

	chunk_size = 0;
	if (len <= 100)
		chunk_size = 20;
	else
		chunk_size = 50;
	return (chunk_size);
}

void	exec_pb_rb(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	exec_cmd(PB, a, b, cmd_lists);
	exec_cmd(RB, a, b, cmd_lists);
}

void	sort_by_chunky(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	int	chunk_size;
	int	chunks;
	int	i;
	int	min;
	int	max;

	chunk_size = split_chunk_size(a->len);
	chunks = a->len / chunk_size + 1;
	i = 0;
	while (i < chunks)
	{
		min = i * chunk_size;
		max = (i++ + 1) * chunk_size;
		while (count_range(a, min, max) > 0)
		{
			if (is_in_range(a->data[0], min + chunk_size / 2, max))
				exec_cmd(PB, a, b, cmd_lists);
			else if (is_in_range(a->data[0], min, min + chunk_size / 2))
				exec_pb_rb(a, b, cmd_lists);
			else
				exec_cmd(RA, a, b, cmd_lists);
		}
	}
	while (b->len)
		search_max_pa(a, b, cmd_lists);
}

void	free_structure(t_stack **a, t_stack **b, t_list **cmd_lists)
{
	if (*a)
	{
		free(*a);
		*a = NULL;
	}
	if (*b)
	{
		free(*b);
		*b = NULL;
	}
	if (cmd_lists)
	{
		ft_lstclear(cmd_lists, free);
		*cmd_lists = NULL;
	}
}

int	init_structure(t_stack **a, t_stack **b, t_list **cmd_lists)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	*cmd_lists = NULL;
	if (!*a || !*b)
	{
		if (*a)
			free(*a);
		if (*b)
			free(*b);
		return (0);
	}
	(*a)->len = 0;
	ft_bzero((*a)->data, sizeof((*a)->data));
	(*b)->len = 0;
	ft_bzero((*b)->data, sizeof((*b)->data));
	return (1);
}

void	start_sort(t_stack *a, t_stack *b, t_list **cmd_lists)
{
	compress_stack(a);
	if (a->len == 2)
		sort_two(a, b, cmd_lists);
	else if (a->len == 3)
		sort_three(a, b, cmd_lists);
	else if (a->len == 4)
		sort_four(a, b, cmd_lists);
	else if (a->len <= 6)
		sort_more_than_five(a, b, cmd_lists);
	else
		sort_by_chunky(a, b, cmd_lists);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmd_lists;

	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (!init_structure(&a, &b, &cmd_lists) || !validate_arg(ac, av, a))
	{
		ft_putendl_fd("Error", 2);
		free_structure(&a, &b, &cmd_lists);
		return (1);
	}
	if (a->len > 50000)
		write(2, "Invalid Argument\n", 19);
	if (is_sorted(a))
	{
		free_structure(&a, &b, &cmd_lists);
		return (0);
	}
	start_sort(a, b, &cmd_lists);
	print_cmds(cmd_lists);
	free_structure(&a, &b, &cmd_lists);
	return (0);
}
