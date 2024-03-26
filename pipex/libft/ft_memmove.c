/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:14:59 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/23 13:31:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s > d)
	{
		i = 0;
		while (i < n)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			*(d + i) = *(s + i);
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <stddef.h>

// int main(void)
// {
// 	char src1[] = "lorem ipsum dolor sit amet";
// 	char *str1;
// 	size_t len1 = 8;
// 	str1 = src1 + 1;
// 	ft_memmove(src1, str1, len1);
// 	printf("my version      -> %s\n", src1);
// 	printf("example         -> %s\n", src1);
// }
