/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:50:03 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/12/18 22:44:12 by kmoriyam         ###   ########.fr       */
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
	if (a[i] > a[i + 1])
	{
		tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;
	}
	command++;
}

void	sb(int *b)
{
	int	tmp;
	int	i;

	i = 0;
	if (b[i] > b[i + 1])
	{
		tmp = b[i];
		b[i] = b[i + 1];
		b[i + 1] = tmp;
	}
	command++;
}

void	ss(int *a, int *b)
{
	sb(a);
	sb(b);
	command++;
}

void	pa(int *a, int *b, int *len_a, int *len_b)
{
	int	i;
	int	tmp;

	if (len_b == 0)
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
	command++;
}

void	pb(int *a, int *b, int *len_a, int *len_b)
{
	int	i;
	int	tmp;

	if (len_a == 0)
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
	command++;
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
	command++;
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
	command++;
}

void	rr(int *a, int *b, int len_a, int len_b)
{
	ra(a, len_a);
	ra(b, len_b);
	command++;
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
	command++;
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
	command++;
}

void	rrr(int *a, int *b, int len_a, int len_b)
{
	rra(a, len_a);
	rrb(b, len_b);
	command++;
}

// void	swap_a(int *a, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		int j = 0;
// 		while (j < 10 - i)
// 		{
// 			sa(&a[j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	min_to_top(int index, int *a, int *b, int *len_a, int *len_b)
{
	int	i;

	i = 0;
	if (index < *len_a / 2 + 1)
	{
		while (index)
		{
			ra(a, *len_a);
			(index)--;
		}
	}
	else
	{
		while (*len_a - index)
		{
			rra(a, *len_a);
			(index)++;
		}
	}
	// ft_printf("1\n");
	pb(a, b, len_a, len_b);
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

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// t_stack a;
	// a->stack[0] = { 5, 4, 2, 7, 8, 1, 10, 6, 3, 9 };
	
	// initialize
	// int a[500] = {14,36,25,48,9,31,42,27,5,11,23,45,37,4,39,2,18,29,30,19,10,7,32,49,21,6,50,17,26,40,34,22,43,35,20,41,28,16,24,33,1,44,8,38,46,12,47,15,13,3};
	int a[500] = { 34,17,9,22,48,3,28,14,47,35,23,5,12,20,30,25,11,1,39,50,27,7,46,16,33,13,18,6,38,44,10,4,21,45,29,31,40,42,26,2,15,37,32,43,36,8,24,19,41,49};
	// int a[500] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int b[500] = {};
	// int a[0] = {};
	// int b[SIZ  E] = { 5, 4, 2, 7, 8, 1, 10, 6, 3, 9 };
	int	len_a;
	int len_b;
	int min;
	int index;

	len_a = 50; // ac - 1
	// if (len_a <= 1)
	// 	return (0);
	len_b = 0;
	// if (len_b <= 1)
	// 	return (0);
	min = 0;
	index = 0;

	// display before
	// search MIN
	min = search_min(&index, a, len_a);
	ft_printf("----- index: %d MIN: %d -----\n\n", index, min);
	ft_printf("a: ");
	for (int i = 0; i < len_a; i++)
		ft_printf("%d ", a[i]);
	ft_printf("\nlen_a: %d\n\n", len_a);
	ft_printf("b: ");
	for (int i = 0; i < len_b; i++)
		ft_printf("%d ", b[i]);
	ft_printf("\nlen_b: %d\n", len_b);
	ft_printf("--------------------------------------------------------------------------\n");

	while (len_a)
	{
		// ft_printf("\nlen_a: %d\n", len_a);
		
		// search MIN
		min = search_min(&index, a, len_a);
		// ft_printf("done\n");
		
		// min index to top
		min_to_top(index, a, b, &len_a, &len_b);
		// ft_printf("top done\n");
		
	}
	// if (a[i] > a[i + 1])
	// 		min_to_top(index, a, b, &len_a, &len_b);
	// 	i++;
	while (len_b)
		pa(a, b, &len_a, &len_b);

	
	// SWAP
	// sa(a);
	// sb(b);
	// ss(a, b);
	// swap_a(a, len_a); // bubble sort

	// ROTATE
	// ra(a, len_a);
	// ra(b, len_b);
	// rr(a, b, len_a, len_b);

	// REVERSE ROTATE
	// rra(a, len_a);
	// rrb(b, len_b);
	// rrr(a, b, len_a, len_b);

	// PUSH
	// pb(a, b, &len_a, &len_b);/
	// ft_printf("a[0]: %d lenA: %d\nb[0]: %d lenB: %d\n", a[0], len_a, b[0], len_b);
	// pa(a, b, &len_a, &len_b);
	// ft_printf("a[0]: %d lenA: %d\nb[0]: %d lenB: %d\n", a[0], len_a, b[0], len_b);


	// display after
	ft_printf("a: ");
	for (int i = 0; i < len_a; i++)
		ft_printf("%d ", a[i]);
	ft_printf("\nlen_a: %d\n\n", len_a);
	ft_printf("b: ");
	for (int i = 0; i < len_b; i++)
		ft_printf("%d ", b[i]);
	ft_printf("\nlen_b: %d\n", len_b);
	ft_printf("\ncommands: %d\n", command);
	ft_printf("--------------------------------------------------------------------------\n");
}
