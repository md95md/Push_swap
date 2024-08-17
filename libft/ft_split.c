/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:13 by agaleeva          #+#    #+#             */
/*   Updated: 2024/08/17 13:35:33 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

// static size_t	ft_wordcount(char const *s, char c)
// {
// 	size_t	count;
// 	size_t	i;

// 	count = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i] != '\0')
// 			count++;
// 		while (s[i] && s[i] != c)
// 			i++;
// 	}
// 	return (count);
// }

// static char	*ft_word(char const *s, char c, size_t *i)
// {
// 	char	*word;
// 	size_t	begin;

// 	begin = 0;
// 	while (s[*i] && s[*i] == c)
// 		(*i)++;
// 	begin = *i;
// 	while (s[*i] && s[*i] != c)
// 		(*i)++;
// 	word = ft_substr(s, begin, *i - begin);
// 	return (word);
// }

// static void	ft_free_split(char **arr, size_t size)
// {
// 	while (size > 0)
// 	{
// 		size--;
// 		free(arr[size]);
// 	}
// 	free(arr);
// }

// static char	**split_words(char const *s, char c, char **arr)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != c)
// 		{
// 			arr[j] = ft_word(s, c, &i);
// 			if (!arr[j])
// 			{
// 				ft_free_split(arr, j);
// 				return (NULL);
// 			}
// 			j++;
// 		}
// 		else
// 			i++;
// 	}
// 	arr[j] = NULL;
// 	return (arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**arr;

// 	if (!s)
// 		return (NULL);
// 	arr = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
// 	if (!arr)
// 		return (NULL);
// 	arr = split_words(s, c, arr);
// 	if (!arr)
// 		return (NULL);
// 	return (arr);
// }
