/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:15:53 by ggalizon          #+#    #+#             */
/*   Updated: 2024/11/26 10:51:22 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i -1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *start)
{
	int		len;
	char	*word;
	int		i;

	while (s[*start] && s[*start] == c)
		(*start)++;
	len = 0;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = '\0';
	*start += len;
	return (word);
}

static void	free_all(char **arr, int allocated)
{
	while (allocated > 0)
		free(arr[--allocated]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		arr[i] = get_word(s, c, &start);
		if (!arr[i])
		{
			free_all(arr, i);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
