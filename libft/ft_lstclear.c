/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:15:14 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/01/02 18:12:08 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(t_command))
{
	t_list	*current;
	t_list	*tmp;

	if (!*lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		ft_lstdelone(current, del);
		current = tmp;
	}
	*lst = NULL;
}
