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
	if (!ft_strlen(temp))
	{
		npos = 0;
		free (temp);
		temp = 0;
		free (o);
		o = 0;
		return (o);
	}
	free (o);
	o = ft_strdup(temp);
	free (temp);
	temp = 0;
	npos = 0;
	return (o);
}

static char	*return_nl(char **o)
{
	char	*npos;
	char	*ret;

	npos = ft_strchr_gnl(*o, 10);
	ret = ft_substr(*o, 0, (npos - *o) + 1);
	npos = 0;
	*o = cat_next_line(*o);
	return (ret);
}

static char	*last_funca(char **o)
{
	char	*ret;

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
	int			i;

	if ((fd < 0) || (fd > RLIMIT_NOFILE) || (BUFFER_SIZE < 1))
		return (0);
	i = 1;
	while (i > 0)
	{
		if (ft_strchr_gnl(oflw, 10))
		{
			ret = return_nl(&oflw);
			return (ret);
		}
		i = read (fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		if (!oflw && i > 0)
			oflw = ft_strdup(buf);
		else if (i > 0)
			oflw = oflw_upd(oflw, buf);
	}
	if (oflw && !i)
		return (last_funca(&oflw));
	return (0);
}
