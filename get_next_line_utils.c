/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 08:57:55 by hmochida          #+#    #+#             */
/*   Updated: 2021/07/25 19:51:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return (0);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	d = malloc((len + 1) * sizeof(char));
	if (!d)
		return (0);
	while (i < len)
	{
		if (*s1)
			d[i++] = *s1++;
		else
			d[i++] = *s2++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	i = 0;
	if ((int)start > ft_strlen(s))
		return (0);
	while (start--)
		s++;
	if (ft_strlen(s) - start >= len)
	{
		d = malloc((len + 1) * (sizeof(char)));
		if (!d)
			return (0);
	}
	else
		d = malloc((ft_strlen(s) - start + 1) * (sizeof(char)));
	if (!d)
		return (0);
	while (len-- && *s)
		d[i++] = *s++;
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*c;
	int		i;

	i = 0;
	l = ft_strlen(s1) + 1;
	c = malloc(l * (sizeof(char)));
	if (!c)
		return (0);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
