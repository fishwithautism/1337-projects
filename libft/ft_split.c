/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azennani <azennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:40 by azennani          #+#    #+#             */
/*   Updated: 2025/11/11 10:37:41 by azennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word && (in_word = 1))
			count++;
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_all(char **arr, int size)
{
	while (size-- > 0)
		free(arr[size]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i[3];

	if (!s || !(result = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (i[1] < count_words(s, c))
	{
		while (s[i[0]] == c)
			i[0]++;
		i[2] = i[0];
		while (s[i[2]] && s[i[2]] != c)
			i[2]++;
		if (!(result[i[1]] = ft_substr(s, i[0], i[2] - i[0])))
			return (free_all(result, i[1]), NULL);
		i[0] = i[2];
		i[1]++;
	}
	result[i[1]] = NULL;
	return (result);
}
