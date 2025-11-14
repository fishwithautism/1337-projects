/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azennani <azennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:08:24 by azennani          #+#    #+#             */
/*   Updated: 2025/11/13 14:02:39 by azennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (dst);
	if (len == 0)
		return (dst);
	d = (char *)dst;
	s = (const char *)src;
	if (d < s || d >= s + len)
		ft_memcpy(d, s, len);
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
#include <stdio.h>
int main ()
{

	char src[] = "Hello World!";
	char dst1[20];
	char dst2[20];
	
	// Test 1: Normal copy
	printf("Test 1 - Normal copy:\n");
	memmove(dst1, src, 13);
	ft_memmove(dst2, src, 13);
	printf("memmove:    '%s'\n", dst1);
	printf("ft_memmove: '%s'\n", dst2);
	printf("Match: %s\n\n", strcmp(dst1, dst2) == 0 ? "✓ PASS" : "✗ FAIL");
	
	// Test 2: Overlapping - move to the right
	printf("Test 2 - Overlapping (dst > src):\n");
	char str1[50] = "ABCDEFGHIJ";
	char str2[50] = "ABCDEFGHIJ";
	memmove(str1 + 3, str1, 5);
	ft_memmove(str2 + 3, str2, 5);
	printf("memmove:    '%s'\n", str1);
	printf("ft_memmove: '%s'\n", str2);
	printf("Match: %s\n\n", strcmp(str1, str2) == 0 ? "✓ PASS" : "✗ FAIL");
	
	// Test 3: Overlapping - move to the left
	printf("Test 3 - Overlapping (dst < src):\n");
	char str3[50] = "ABCDEFGHIJ";
	char str4[50] = "ABCDEFGHIJ";
	memmove(str3, str3 + 3, 5);
	ft_memmove(str4, str4 + 3, 5);
	printf("memmove:    '%s'\n", str3);
	printf("ft_memmove: '%s'\n", str4);
	printf("Match: %s\n\n", strcmp(str3, str4) == 0 ? "✓ PASS" : "✗ FAIL");
	
	// Test 4: Return value check
	printf("Test 4 - Return value:\n");
	char buffer[20];
	void *ret1 = memmove(buffer, src, 5);
	void *ret2 = ft_memmove(buffer, src, 5);
	printf("memmove return:    %p\n", ret1);
	printf("ft_memmove return: %p\n", ret2);
	printf("Match: %s\n", ret1 == ret2 ? "✓ PASS" : "✗ FAIL");
	
	return 0;
}