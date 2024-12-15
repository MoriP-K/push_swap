/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:57:47 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/11/02 22:42:00 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char str[] = "1234";
// 	char str2[] = "567";
// 	printf("%lu\n", ft_strlcpy(str, str2, sizeof(str2)));
// 	for (int i=0; i<3;i++)
// 		printf("%c", str2[i]);
// }
