/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azennani <azennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 09:40:54 by azennani          #+#    #+#             */
/*   Updated: 2025/11/09 09:40:55 by azennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	end = (char *)s + ft_strlen(s);
	while (--end >= (char *)s)
		if (*end == (char)c)
			return (end);
	return (NULL);
}
