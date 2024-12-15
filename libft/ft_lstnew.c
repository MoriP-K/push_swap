/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:11:07 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/12/15 20:11:34 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list *lst;
// 	char str[] = "123456";

// 	lst = ft_lstnew(str);
// 	printf("%p\n", lst);
// 	free(lst);
// 	return (0);
// }