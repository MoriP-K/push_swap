/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:50:03 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/12/16 22:35:55 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>

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

	if (len_b == 0)
		return ;
	tmp = b[0];
	a[0] = b[0];
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

void	swap_a(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		int j = 0;
		while (j < 10 - i)
		{
			sa(&a[j]);
			j++;
		}
		i++;
	}
}

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// t_stack a;
	// a->stack[0] = { 5, 4, 2, 7, 8, 1, 10, 6, 3, 9 };
	
	// initialize
	// int a[SIZE] = { 5, 4, 2, 7, 8, 1, 10, 6, 3, 9 };
	// int b[0] = {};
	int a[0] = {};
	int b[SIZE] = { 5, 4, 2, 7, 8, 1, 10, 6, 3, 9 };
	int	len_a;
	int len_b;
	int i;
	int min;
	int index;

	len_a = sizeof(a) / sizeof(a[0]);	
	// if (len_a <= 1)
	// 	return (0);
	len_b = sizeof(b) / sizeof(b[0]);
	// if (len_b <= 1)
	// 	return (0);
	i = 0;
	min = 0;
	index = 0;

	// display before
	ft_printf("a: ");
	for (int i = 0; i < len_a; i++)
		ft_printf("%d ", a[i]);
	ft_printf("\n");
	ft_printf("b: ");
	for (int i = 0; i < len_b; i++)
		ft_printf("%d ", b[i]);
	ft_printf("\n---------------------------------------------------------------------\n");
	// search MIN
	min = a[0];
	while (i < len_a)
	{
		if (min > a[i])
			index = i;
		i++;
	}
	ft_printf("%d\n", min);
	if (len_a % 2 == 0)
	{
		if (index < len_a / 2 + 1)
		{
			
		}
		
	}
	else
	{
		
	}
	if (len_b % 2 == 1)
	{
		
	}
	else 
	{
		
	}
	// swap
	// sa(a);
	// sb(b);
	// ss(a, b);
	// swap_a(a, len_a); // bubble sort

	// rotate
	// ra(a, len_a);
	// ra(b, len_b);
	// rr(a, b, len_a, len_b);

	// reverse rotate
	// rra(a, len_a);
	// rrb(b, len_b);
	// rrr(a, b, len_a, len_b);

	// push
	// pb(a, b, &len_a, &len_b);
	// ft_printf("a[0]: %d lenA: %d\nb[0]: %d lenB: %d\n", a[0], len_a, b[0], len_b);
	// pa(a, b, &len_a, &len_b);
	// ft_printf("a[0]: %d lenA: %d\nb[0]: %d lenB: %d\n", a[0], len_a, b[0], len_b);


	// display after
	ft_printf("a: ");
	for (int i = 0; i < len_a; i++)
		ft_printf("%d ", a[i]);
	ft_printf("\n");
	ft_printf("b: ");
	for (int i = 0; i < len_b; i++)
		ft_printf("%d ", b[i]);
	ft_printf("\n");	
}
