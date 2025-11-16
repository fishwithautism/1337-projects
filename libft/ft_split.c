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
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s != c && !in_word && (in_word = 1))
			count++;
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count + 1);
}

static void	clear_split(char **arr, int size)
{
	while (size-- > 0)
		free(arr[size]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	firstp;
	unsigned int	i;
	unsigned int	lastp;

	split = ft_calloc(count_words(s, c), sizeof(char *))
	if (!split)	
		return (NULL);
	fp = 0;
	i = 0;
	while (i < (unsigned int)count_words(s, c) - 1)
	{
		while (s[fp] && s[fp] == c)
			fp++;
		lp = fp;
		while (s[lp] && s[lp] != c)
			lp++;
		split[i] = ft_substr(s, fp, lp - fp);
		if (!split[i])
			return (clear_split(split, i));
		fp = lp;
		i++;
	}
	return (split);
}
