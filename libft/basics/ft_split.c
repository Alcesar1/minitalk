/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:35:12 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/10/27 13:25:44 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fcount(char const *s, char c);
static char		*copy(char const *s, char c);
static void		free_split(char **array, size_t i);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	count;
	int		i;

	i = 0;
	count = fcount(s, c);
	array = ft_calloc(count +1, sizeof(char *));
	if (!(array))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		array[i] = copy(s, c);
		if (!array[i])
			return (free_split(array, i), NULL);
		i++;
		while (*s && *s != c)
			s++;
	}
	array[i] = NULL;
	return (array);
}

static char	*copy(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (ft_substr(s, 0, len));
}

static size_t	fcount(char const *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	free_split(char **array, size_t i)
{
	while (i > 0)
	{
		free(array[i - 1]);
		i--;
	}
	free(array);
}
