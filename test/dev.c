/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:22:57 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/11 19:35:16 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 2

int		main()
{
	int		fd;
	ssize_t	buff_s;
	char	*line;


	fd = open("./lala.txt", O_RDONLY);
	if (fd < 0)
		return (printf("Erro na abertura do arquivo!"));
	while ((line = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))) &&
			(buff_s = read(fd, line, BUFFER_SIZE)))
	{
		char	buf = buff_s + '0';
		write(1, &buf, 1);
		write(1, "\t", 1);
		write(1, line, buff_s);
		write(1, "\n", 1);
		//printf("%zd\t%s\n", buff_s, line);
		free(line);
	}
		printf("%zd\t%s\n", buff_s, line);
		printf("%zd\t%s\n", buff_s, line);
		printf("%zd\t%s\n", buff_s, line);
		printf("%zd\t%s\n", buff_s, line);
		printf("%zd\t%s\n", buff_s, line);
	close(fd);
}
