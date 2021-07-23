/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 07:36:16 by hmochida          #+#    #+#             */
/*   Updated: 2021/07/23 01:05:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h> //prevenção de overflow
# include <sys/param.h>
# include <sys/resource.h> //RLIMIT_NOFILE -> Limit on number of open files.
# include <fcntl.h>

//# define BUFFER_SIZE	50 //remover depois de testar

char	*get_next_line(int fd);


int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c); //retorna indice de c
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

#endif
