/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:10:36 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/11 20:35:15 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("./text.txt", O_RDONLY);
	if (fd < 0)
		return (printf("Erro na abertura de arquivo!\n"));
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s", line);
		printf("\n");
	}
	return (0);
}
