/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:09:52 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/12/15 15:14:10 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s_p;
	char	char_c;

	if (!s)
		return (NULL);
	i = 0;
	s_p = (char *)s;
	char_c = (char)c;
	while (s_p[i])
	{
		if (s_p[i] == char_c)
			return (&s_p[i]);
		i++;
	}
	if (char_c == '\0')
		return (&s_p[i]);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char s1[] = "01234";

// 	printf("my: %s\n", ft_strchr(s1, '4'));
// }