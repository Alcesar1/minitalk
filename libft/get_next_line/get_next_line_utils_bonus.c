/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:42:02 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2026/02/11 09:48:49 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	if (s == 0)
		return (NULL);
	len = ft_strlen(s) + 1;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (s == 0)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > (slen - start))
		len = (slen - start);
	str = malloc((len +1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len +1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;
	size_t	lenstr;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	lenstr = ls1 + ls2 +1;
	if (s1 == 0 && s2 == 0)
		return (malloc(0));
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	str = malloc(lenstr * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ls1 + 1);
	ft_strlcpy(str + ls1, s2, ls2 + 1);
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (s == NULL)
		return (last);
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	return (last);
}
