/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:53:03 by hmochida          #+#    #+#             */
/*   Updated: 2021/07/25 17:51:38 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*oflw_upd(char *o, char *b)
{
	char	*temp;

	temp = ft_strjoin (o, b);
	free(o);
	o = ft_strdup(temp);
	free(temp);
	temp = 0;
	return (o);
}

static char	*cat_next_line(char *o)
{
	char	*npos;
	char	*temp;

	npos = ft_strchr_gnl(o, 10);
	temp = ft_substr(o, (npos - o) + 1, ft_strlen(o) - (npos - o));
	free (o);
	o = ft_strdup(temp);
	free (temp);
	temp = 0;
	npos = 0;
	return (o);
}

static char	*return_nl(char **o, int *i)
{
	char	*npos;
	char	*ret;

	npos = ft_strchr_gnl(*o, 10);
	ret = ft_substr(*o, 0, (npos - *o) + 1);
	i[1] = 1;
	npos = 0;
	*o = cat_next_line(*o);
	return (ret);
}

static char	*last_funca(char **o, int *i)
{
	char	*ret;

	if (i[1])
		ret = ft_strjoin(*o, "\n");
	else
		ret = ft_strdup(*o);
	free(*o);
	*o = NULL;
	return (ret);
}

char	*get_next_line(int fd)
	{
	static char	*oflw;
	char		buf[BUFFER_SIZE + 1];
	char		*ret;
	static int	i[2];

	if ((fd < 0) || (fd > RLIMIT_NOFILE) || (BUFFER_SIZE < 1))
		return (0);
	i[0] = 1;
	while (i[0])
	{
		if (ft_strchr_gnl(oflw, 10))
		{
			ret = return_nl(&oflw, i);
			return (ret);
		}
		i[0] = read (fd, buf, BUFFER_SIZE);
		buf[i[0]] = '\0';
		if (!oflw && i[0])
			oflw = ft_strdup(buf);
		else if (i[0])
			oflw = oflw_upd(oflw, buf);
	}
	if (oflw && !i[0])
		return (last_funca(&oflw, i));
	return (0);
}
/*
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*oflw;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*ret;
	char		*npos;
	int			i;

	if ((fd < 0) || (fd > RLIMIT_NOFILE) || (BUFFER_SIZE < 1))
		return (0);
	i = 1;
	while (i)
	{
		if (ft_strlen(oflw))
		{
			npos = ft_strchr(oflw, 10);
			if (npos)
			{
				ret = ft_substr(oflw, 0, (npos - oflw) + 1);
				temp = ft_substr(oflw, (npos - oflw) + 1, ft_strlen(oflw) - (npos - oflw));
				free (oflw);
				oflw = ft_strdup(temp);
				free (temp);
				return (ret);
			}
		}
		i = read (fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		if (!oflw && i)
			oflw = ft_strdup(buf);
		else if (i)
		{
			temp = ft_strjoin (oflw, buf);
			free(oflw);
			oflw = ft_strdup(temp);
			free(temp);
			temp = 0;
		}
	}
	if (oflw && !i)
	{
		ret = ft_strdup(oflw);
		free(oflw);
		oflw = NULL;
		return (ret);
	}
	return (0);
}
*/