/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:14:55 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/23 13:31:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	ch;

	src = (unsigned char *)s;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		*src = ch;
		src++;
		i++;
	}
	return (s);
}
// int main(void)
// {
// 	unsigned char str[] = "Hello Wold!";
// 	ft_memset(str, 'a', 11);
// 	printf("str: %s\n", str);
// 	return (0);
// }
