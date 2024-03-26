/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:14:29 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/23 13:31:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char str[] = "Hello, World!";
// 	char ch = 'W';
// 	char *result = ft_memchr(str, ch, 10); // Arbitrary size

// 	if (result != NULL)
// 	{
// 		printf("Character '%c' found in NULL pointer: %s\n", ch, result);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found or NULL pointer\n", ch);
// 	}
// 	return 0;
// }
