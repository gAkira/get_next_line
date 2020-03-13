/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:10:36 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/13 17:46:46 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("./these-are-four-words", O_RDONLY);
	if (fd < 0)
		return (printf("Erro na abertura de arquivo!\n"));
	while (get_next_line_bonus(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	get_next_line_bonus(fd, &line);
	free(line);
	return (0);
}
