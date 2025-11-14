/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azennani <azennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:35:18 by azennani          #+#    #+#             */
/*   Updated: 2025/10/28 10:31:00 by azennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

/*#include <stdio.h>

int	main(int argc, char** argv)
{
	int size = atoi(argv[1]);
	char *str = ft_calloc(atoi(argv[1]), 1);
	while(!*str && size--)
		printf("%p\n", str++);
}*/