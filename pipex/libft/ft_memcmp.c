/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:14:36 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/23 13:31:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_temp;
	const unsigned char	*s2_temp;

	i = 0;
	s1_temp = (const unsigned char *)s1;
	s2_temp = (const unsigned char *)s2;
	while (i < n)
	{
		if (*(s1_temp + i) != *(s2_temp + i))
			return (*(s1_temp + i) - *(s2_temp + i));
		i++;
	}
	return (0);
}
// int main()
// {
// 	int arr1[] = {1, 2, 3, 4, 5};
// 	int arr2[] = {1, 2, 3, 4, 6};
// 	int result = ft_memcmp(arr1, arr2, sizeof(arr1));

// 	if (result == 0)
// 	{
// 		printf("Integer arrays are identical.\n");
// 	}
// 	else
// 	{
// 		printf("Integer arrays are different. Result: %d\n", result);
// 	}
// 	return 0;
// }
