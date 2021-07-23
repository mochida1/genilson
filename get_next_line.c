/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:57:58 by hmochida          #+#    #+#             */
/*   Updated: 2021/07/23 20:18:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*oflw;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*ret;
	char		*npos;
	int 		i;


	//checagem de erros antes;
	i = 1;
	while (i){
		if (ft_strlen(oflw))  //se existir oflw
		{
			npos = ft_strchr(oflw, 10);
				if (npos)					//se existir \n bota até npos como string em ret. atualiza oflw. retorna ret.
					{
					ret = ft_substr(oflw, 0, (npos - oflw) + 1);
					//*(npos + 1) = '\0';
					temp = ft_substr(oflw, (npos - oflw) + 1, ft_strlen(oflw) - (npos - oflw)); //copia da posição de \n +1 até o final da string
					free (oflw);
					oflw = ft_strdup(temp);
					free (temp);
					return (ret);
					}
		}
		i = read (fd, buf, BUFFER_SIZE);
		buf[i] = '\0'; // era buf[BUFFER_SIZE]
		if (!oflw &&  i)
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
		return(ret);
	}
	return (0);
}

/*
while (i)
{
	se existe oflw
		se parse oflw for \n = 1;
			recorta até \n e cat em ret;
			joga (&\n) +1 pra temp
			free(oflw);
			strldup (temp, -1)
			retorna ret;


	i = read (fd, buf, BUFFER_SIZE))
	se parse buf for \n = 1;
		strjoin ret,temp
		recorta buf depois do 1o \n e joga em oflw
		retorna ret;
	else
		cat buf em oflw;
}
if (oflw)
	return(oflw)
return (0);
*/
