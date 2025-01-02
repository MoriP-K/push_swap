/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:50:03 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/01/02 20:28:15 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

int command = 0;

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

void	pa(int *a, int *b, int *len_a, int *len_b)
{
	int	i;
	int	tmp;

	if (*len_b == 0)
		return ;
	tmp = b[0];
	(*len_b)--;
	i = 0;
	while (i < *len_b)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*len_a)++;
	i = 1;
	while (i < *len_a)
	{
		a[*len_a - i] = a[*len_a - i - 1];
		i++;
	}
	a[0] = tmp;
}

void	pb(int *a, int *b, int *len_a, int *len_b)
{
	int	i;
	int	tmp;

	if (*len_a == 0)
		return ;
	tmp = a[0];
	(*len_a)--;
	i = 0;
	while (i < *len_a)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*len_b)++;
	i = 1;
	while (i < *len_b)
	{
		b[*len_b - i] = b[*len_b - i - 1];
		i++;
	}
	b[0] = tmp;
}

void	ra(int *a, int len)
{
	int	i;
	int	tmp;

	tmp = a[0];
	i = 1;
	while (i < len)
	{
		a[i - 1] = a[i];
		i++;
	}
	a[i - 1] = tmp;
}

void	rb(int *b, int len)
{
	int	i;
	int	tmp;

	tmp = b[0];
	i = 1;
	while (i < len)
	{
		b[i - 1] = b[i];
		i++;
	}
	b[i - 1] = tmp;
}

void	rr(int *a, int *b, int len_a, int len_b)
{
	ra(a, len_a);
	ra(b, len_b);
}

void	rra(int *a, int len)
{
	int	i;
	int	tmp;

	tmp = a[len - 1];
	i = 1;
	while (i < len)
	{
		a[len - i] = a[len - i - 1];
		i++;
	}
	a[0] = tmp;
}

void	rrb(int *b, int len)
{
	int	i;
	int	tmp;

	tmp = b[len - 1];
	i = 1;
	while (i < len)
	{
		b[len - i] = b[len - i - 1];
		i++;
	}
	b[0] = tmp;
}

void	rrr(int *a, int *b, int len_a, int len_b)
{
	rra(a, len_a);
	rrb(b, len_b);
}

void	sort(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
				sa(&array[j]);
			j++;
		}
		i++;
	}
}

int	is_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_double(int *stack, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (stack[i] == stack[j])
			{
				// ft_printf("%d = %d, %d = %d\n", i, stack[i], j, stack[j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_memflow(int sign, long result, char **endptr, char *nptr)
{
	if (sign == 1 && result > (LONG_MAX - (*nptr - '0')) / 10)
	{
		*endptr = ++nptr;
		return (1);
	}
	else if (sign == -1 && result > (LONG_MAX - (*nptr - '0')) / 10)
	{
		*endptr = ++nptr;
		return (-1);
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
	long int	result;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -sign;
	result = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		return (set_endptr(result, endptr, (char *)&nptr[--i]));
	while (nptr[i] && ft_isdigit((int)nptr[i]))
	{
		if (ft_memflow(sign, result, endptr, (char *)&(nptr[i])) == 1)
			return (LONG_MAX);
		if (ft_memflow(sign, result, endptr, (char *)&(nptr[i])) == -1)
			return (LONG_MIN);
		result = result * 10 + (nptr[i++] - '0');
	}
	if (endptr)
		*endptr = (char *)&nptr[i];
	return (sign * result);
}

char	**set_arg(int ac, char **av, int *len)
{
	char	**array;

	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		array = ft_split(av[1], ' ');
		*len = (int)ft_arrlen(array);
	}
	else
	{
		array = &av[1];
		*len = ac - 1;
	}
	return (array);
}

int	validate_arg(int ac, char **av, int *stack, int *len)
{
	int		i;
	char	*endptr;
	long	num;
	char	**array;

	array = set_arg(ac, av, len);
	i = 0;
	while (i < *len)
	{
		endptr = NULL;
		num = (int)ft_strtol(array[i], &endptr);
		if (*endptr != '\0' || num < INT_MIN || num > INT_MAX)
			return (0);
		stack[i] = (int)num;
		i++;
	}
	if (is_sorted(stack, *len))
		return (0);
	if (check_double(stack, *len))
		return (0);
	return (1);
}

int	*numcpy(int *dest, int *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	assign_index(int num, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (0);
}

void	compress_stack(int *stack, int len)
{
	int	*compressed;
	int	i;

	compressed = malloc(sizeof(int) * len);
	if (!compressed)
		return ;
	compressed = numcpy(compressed, stack, len);
	sort(compressed, len);
	i = 0;
	while (i < len)
	{
		stack[i] = assign_index(stack[i], compressed, len);
		i++;
	}
	free(compressed);
}

void	print_cmds(t_list *list)
{
	t_list		*current;
	t_command	cmd;

	current = list;
	while (current)
	{
		cmd = (t_command)current->data;
		if (cmd == CMD_SA)
			write(1, "sa\n", 3);
		else if (cmd == CMD_SB)
			write(1, "sb\n", 3);
		else if (cmd == CMD_SS)
			write(1, "ss\n", 3);
		else if (cmd == CMD_RA)
			write(1, "ra\n", 3);
		else if (cmd == CMD_RB)
			write(1, "rb\n", 3);
		else if (cmd == CMD_RR)
			write(1, "rr\n", 3);
		else if (cmd == CMD_RRA)
			write(1, "rra\n", 3);
		else if (cmd == CMD_RRB)
			write(1, "rrb\n", 3);
		else if (cmd == CMD_RRR)
			write(1, "rrr\n", 3);
		else if (cmd == CMD_PA)
			write(1, "pa\n", 3);
		else if (cmd == CMD_PB)
			write(1, "pb\n", 3);
		current = current->next;
	}
}

void	add_cmd(t_list **list, t_command cmd)
{
	t_list	*node;

	node = ft_lstnew(cmd);
	if (!node)
		return ;
	ft_lstadd_back(list, node);
}

void	sort_two(int *a, t_list **commands)
{
	int	i;
	(void)commands;

	i = 0;
	// cmd = CMD_SA;
	if (a[i] > a[i + 1])
	{
		sa(a);
		ft_printf("sa\n"); // q
		// add_cmd(commands, CMD_SA);
		command++;
	}
}

int	search_max(int *stack, int len)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < len)
	{
		if (max < stack[i])
			max = stack[i];
		i++;
	}
	return (max);
}

int	search_min(int *stack, int len)
{
	int	min;
	int	i;

	i = 0;
	min = 0;
	while (i < len)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min);
}

int	search_max_index(int *stack, int len)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = 0;
	index = 0;
	while (i < len)
	{
		if (max < stack[i])
		{
			max = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	search_min_index(int *stack, int len)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack[0];
	index = 0;
	while (i < len)
	{
		if (min > stack[i])
		{
			min = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	search_min_pb(int *a, int *b, int *len_a, int *len_b)
{
	int	min_index;

	min_index = search_min_index(a, *len_a);
	if (min_index < *len_a / 2)
	{
		while (min_index)
		{
			ra(a, *len_a);
			ft_printf("ra\n"); // q
			command++;
			min_index--;
		}
	}
	else
	{
		while (*len_a > min_index)
		{
			rra(a, *len_a);
			ft_printf("rra\n"); // q
			command++;
			min_index++;
		}
	}
	pb(a, b, len_a, len_b);
	ft_printf("pb\n"); // q
	command++;
}

void	search_max_pa(int *a, int *b, int *len_a, int *len_b)
{
	int	max_index;

	max_index = search_max_index(b, *len_b);
	if (max_index <= *len_b / 2)
	{
		while (max_index)
		{
			rb(b, *len_b);
			ft_printf("rb\n"); // q
			max_index--;
			command++;
		}
	}
	else
	{
		while (*len_b > max_index)
		{
			rrb(b, *len_b);
			ft_printf("rrb\n"); // q
			max_index++;
			command++;
		}
	}
	pa(a, b, len_a, len_b);
	ft_printf("pa\n"); // q
	command++;
}

void	sort_three(int *a, int len)
{
	int	max_index;

	max_index = search_max_index(a, len);
	if (max_index == 0)
	{
		ra(a, len);
		ft_printf("ra\n"); // q
		if (a[0] > a[1])
		{
			sa(a);
			ft_printf("sa\n"); // q
		}
	}
	else if (max_index == 1)
	{
		rra(a, len);
		ft_printf("rra\n"); // q
		if (a[0] > a[1])
		{
			sa(a);
			ft_printf("sa\n"); // q
		}
	}
	else if (a[0] > a[1] && max_index == 2)
	{
		sa(a);
		ft_printf("sa\n"); // q
	}
}

void	sort_four(int *a, int *b, int *len_a, int *len_b)
{
	search_min_pb(a, b, len_a, len_b);
	sort_three(a, *len_a);
	pa(a, b, len_a, len_b);
	ft_printf("pa\n"); // q
	command++;
}

void	sort_more_than_five(int *a, int *b, int *len_a, int *len_b)
{
	while (*len_a > 3)
	{
		search_min_pb(a, b, len_a, len_b);
	}
	sort_three(a, *len_a);
	while (*len_b)
	{
		pa(a, b, len_a, len_b);
		ft_printf("pa\n"); // q
		command++;
	}
}
// 現在のチャンクのMINとMAXに残っている要素数をカウント
int	count_range(int *stack, int len, int min, int max)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < len)
	{
		if (min <= stack[i] && stack[i] < max)
			count++;
		i++;
	}
	return (count);
}

int	is_in_range(int num, int min, int max)
{
	return (min <= num && num < max);
}

void	sort_by_chunky(int *a, int *b, int *len_a, int *len_b)
{
	int	chunk_size;
	int	chunks;
	int	i;
	int	min;
	int	max;

	if (*len_a <= 100)
		chunk_size = 20;
	else
		chunk_size = 50;
	chunks = *len_a / chunk_size + 1;
	i = 0;
	while (i < chunks)
	{
		min = i * chunk_size;
		max = (i + 1) * chunk_size;
		while (count_range(a, *len_a, min, max) > 0)
		{
			if (is_in_range(a[0], min + chunk_size / 2, max))
			{
				pb(a, b, len_a, len_b);
				ft_printf("pb\n"); // q
				command++;
			}
			else if (is_in_range(a[0], min, min + chunk_size / 2))
			{
				pb(a, b, len_a, len_b);
				rb(b, *len_b);
				ft_printf("pb\n"); // q
				ft_printf("rb\n"); // q
				command += 2;
			}
			else
			{
				ra(a, *len_a);
				ft_printf("ra\n"); // q
				command++;
			}
		}
		i++;
	}
	while (*len_b)
		search_max_pa(a, b, len_a, len_b);
}

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	a[50000];
	int	b[50000];
	int	len_a;
	int	len_b;
	t_list *commands;

	len_a = 0;
	if (!validate_arg(ac, av, a, &len_a))
	{
		// ft_putendl_fd("Error", 2);
		return (1);
	}
	// if (len_a > 50000)
	// 	ft_putendl_fd("Invalid Argument", 2);
	len_b = 0;
	if (is_sorted(a, len_a))
		return (0);
	
	// 座標圧縮
	compress_stack(a, len_a);
	
	// 出力するコマンドを保存するリストを作成
	commands = NULL;
	
	// ソートの実行
	if (len_a == 2)
		sort_two(a, &commands);
	else if (len_a == 3)
		sort_three(a, len_a);
	else if (len_a == 4)
		sort_four(a, b, &len_a, &len_b);
	else if (len_a <= 6)
		sort_more_than_five(a, b, &len_a, &len_b);
	else
		sort_by_chunky(a, b, &len_a, &len_b);
	// print_cmds(commands);
	// ソートできたかチェック
	// if (is_sorted(a, len_a))
	// {
	// 	// ft_printf("sorted\n");
	// 	return (0);
	// }

	// while (commands)
	// {
	// 	ft_printf("data: %s\n", commands->data);
	// 	commands = commands->next;
	// }
	// display after
	// ft_printf("a: ");
	// for (int i = 0; i < len_a; i++)
	// 	ft_printf("%d ", a[i]);
	// ft_printf("\nlen_a: %d\n\n", len_a);
	// ft_printf("b: ");
	// for (int i = 0; i < len_b; i++)
	// 	ft_printf("%d ", b[i]);
	// ft_printf("\nlen_b: %d\n", len_b);
	// ft_printf("\ncommands: %d\n", command);
	// ft_printf("--------------------------------------------------------------------------\n");
}
