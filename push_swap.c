/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:50:03 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/12/30 14:30:39 by kmoriyam         ###   ########.fr       */
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
	// if (a[i] > a[i + 1])
	// {
		tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;
	// }
}

void	sb(int *b)
{
	int	tmp;
	int	i;

	i = 0;
	// if (b[i] > b[i + 1])
	// {
		tmp = b[i];
		b[i] = b[i + 1];
		b[i + 1] = tmp;
	// }
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
	while (i < len)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	min_to_top(int index, int *a, int *b, int *len_a, int *len_b)
{
	int	i;

	i = 0;
	if (index < *len_a / 2 + 1)
	{
		while (index)
		{
			ra(a, *len_a);
			ft_printf("ra\n"); //q
			command++;
			index--;
		}
	}
	else
	{
		while (*len_a - index)
		{
			rra(a, *len_a);
			ft_printf("rra\n"); //q
			command++;
			index++;
		}
	}
	pb(a, b, len_a, len_b);
	ft_printf("pb\n"); //q
	command++;
}

int	search_min(int *index, int *a, int len_a)
{
	int	min;
	int	i;

	i = 0;
	min = a[0];
	*index = 0;
	while (i < len_a)
	{
		if (min > a[i])
		{
			min = a[i];
			*index = i;
		}
		i++;
	}
	return (min);
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

		// array = ft_split(av[1], ' ');
		// if (!array)
		// 	return (0);
		// return (1);

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

int	validate_arg(int ac, char **av, int *stack)
{
	int		i;
	char	*endptr;
	long	num;

	// if (ac != 101 && ac != 501 && ac < 2)
	// 	return (0);
	i = 1;
	while (i < ac)
	{
		endptr = NULL;
		num = (int)ft_strtol(av[i], &endptr);
		if (*endptr != '\0' || num < INT_MIN | num > INT_MAX)
			return (0);
		stack[i - 1] = (int)num;
		i++;
	}
	if (check_double(stack, ac - 1))
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
		// len--;
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
	// ft_printf("copy a: ");
	// for (int i = 0; i < len; i++)
	// 	ft_printf("%d ", stack[i]);
	// ft_printf("\n");
	sort(compressed, len);
	// ft_printf("sorted a: ");
	// for (int i = 0; i < len; i++)
	// 	ft_printf("%d ", compressed[i]);
	// ft_printf("\n");
	i = 0;
	while (i < len)
	{
		stack[i] = assign_index(stack[i], compressed, len);
		i++;
	}
	// ft_printf("pressed a: ");
	// for (int i = 0; i < len; i++)
	// 	ft_printf("%d ", stack[i]);
	// ft_printf("\n");
	free(compressed);
}

void	split_stack(int *a, int *b, int *len_a, int *len_b)
{
	int	center;
	int	len;
	int	i;
	int	j;
	center = (*len_a - 1) / 2;
	len = *len_a;
	i = 0;
	while (i < len)
	{
		if (center < a[i])
		{
			j = i;
			if (i < center)
			{
				while (j)
				{
					ra(a, *len_a);
					ft_printf("ra\n"); //q
					command++;
					j--;
				}
			}
			else
			{
				while (j)
				{
					rra(a, *len_a);
					ft_printf("rra\n"); //q
					command++;
					j--;
				}
			}
			pb(a, b, len_a, len_b);
			ft_printf("pb\n"); //q
			command++;
			i = -1;
		}
		i++;
	}
}

// void	split_stack(int *a, int *b, int *len_a, int *len_b)
// {
// 	int	center;
// 	int	i;
// 	center = *len_a / 2;
// 	i = 0;
// 	while (i < center)
// 	{
// 		if (center < a[0])
// 		{
// 			pb(a, b, len_a, len_b);
			// ft_printf("pb\n"); //q
// 			command++;
// 		}
// 		else
// 		{
// 			ra(a, *len_a);
			// ft_printf("ra\n"); //q
// 			command++;
// 		}
// 		i++;
// 	}
// }

void	swap_two(int *a)
{
	int	i;

	i = 0;
	if (a[i] > a[i + 1])
	{
		sa(a);
		ft_printf("sa\n"); //q
		command++;
	}
}

int	search_max(int *a, int len)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < len)
	{	
		if (max < a[i])
			max = a[i];
		i++;
	}
	return (max);
}

void	swap_three(int *a, int len)
{
	int	max;

	max = search_max(a, len);
	// ft_printf("max: %d\n", max);
	if (a[0] == max)
	{	
		ra(a, len);
		ft_printf("ra\n"); //q
		if (a[0] > a[1])
		{
			sa(a);
			ft_printf("sa\n"); //q
		}
	}
	if (a[1] == max)
	{
		rra(a, len);
		ft_printf("rra\n"); //q
		if (a[0] > a[1])
		{
			sa(a);
			ft_printf("sa\n"); //q
		}
	}
	if (a[0] > a[1] && a[2] == max)
	{
		sa(a);
		ft_printf("sa\n"); //q
	}
}

void	swap_four(int *a, int *b, int *len_a, int *len_b)
{
	int	max;

	max = search_max(a, *len_a);
	pb(a, b, len_a, len_b);
	swap_three(a, *len_a);
	pa(a, b, len_a, len_b);

}

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	a[500];
	int b[500];
	int	len_a;
	int len_b;
	int min;
	int index;
	int	center;

	if (!validate_arg(ac, av, a))
	{
		// ft_putendl_fd("Error", 2);
		return (1);
	}
	len_a = ac - 1;
	// ft_printf("len %d\n", len_a);
	len_b = 0;
	min = 0;
	index = 0;

	if (is_sorted(a, len_a))
	{
		// ft_printf("already sorted\n");
		return (0);
	}
	// ft_putendl_fd("OK! Let's sorting!",1);
	
	// 座標圧縮 引数1個のときの処理
	// ft_printf("len: %d\n", len_a);
	compress_stack(a, len_a);

	// 2, 3, 4, 5, 6のときの最適化したソート
	if (len_a == 2)
		swap_two(a);
	if (len_a == 3)
		swap_three(a, len_a);
	if (is_sorted(a, len_a))
		return (0);
	split_stack(a, b, &len_a, &len_b);

	while (len_a)
	{
		// search MIN
		min = search_min(&index, a, len_a);
		// min index to top
		min_to_top(index, a, b, &len_a, &len_b);
	}
	center = len_b / 2;
	while (center)
	{
		rb(b, len_b);
		ft_printf("rb\n"); //q
		center--;
		command++;
	}
	while (len_b - center > 0)
	{
		pa(a, b, &len_a, &len_b);
		ft_printf("pa\n"); //q
		center++;
		command++;
	}
	while (len_a)
	{
		// search MIN
		min = search_min(&index, a, len_a);
		// min index to top
		min_to_top(index, a, b, &len_a, &len_b);
	}
	while (len_b)
	{
		pa(a, b, &len_a, &len_b);
		ft_printf("pa\n"); //q
		command++;
	}

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
	// python3 push_swap_tester.py -l 100 -c 10
	
}
