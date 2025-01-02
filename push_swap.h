/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:10:24 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/01/02 20:27:29 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef SIZE
#  define SIZE 10
# endif

typedef enum s_command {
	NONE = 0,
	CMD_SA = 1,
	CMD_SB = 2,
	CMD_SS = 3,
	CMD_RA = 4,
	CMD_RB = 5,
	CMD_RR = 6,
	CMD_RRA = 7,
	CMD_RRB = 8,
	CMD_RRR = 9,
	CMD_PA = 10,
	CMD_PB = 11,
}	t_command;

typedef struct s_stack
{
	int	stack[50000];
	int	len;
}	t_stack;

#endif