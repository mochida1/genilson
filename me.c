/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:30:08 by hmochida          #+#    #+#             */
/*   Updated: 2021/07/23 20:21:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include "unistd.h"

int main (void)
{
	int fd;
	char *texticulo;

	fd = open("me.txt", O_RDONLY);


	texticulo = get_next_line(fd);
	printf("%s",texticulo);
	free(texticulo);
	texticulo = 0;

	texticulo = get_next_line(fd);
	printf("%s",texticulo);
	free(texticulo);
	texticulo = 0;

	texticulo = get_next_line(fd);
	printf("%s",texticulo);
	free(texticulo);
	texticulo = 0;

	/*
	while (texticulo)
	{
	texticulo = get_next_line(fd);
	printf("%s",texticulo);
	}
	free(texticulo);
	*/
	close(fd);
}
