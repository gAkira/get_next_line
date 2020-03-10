/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:50:31 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/10 19:51:38 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	put_line_file(char **line, char **file, size_t endl)
{
	int		rtrn_value;
	char	*aux;

	write(1, ">>>> Entrou em put_line_file!\n", 30);
	
	rtrn_value = 1;
	if (find_char(*file, '\n') < 0 && find_char(*file, EOF) >= 0)
		rtrn_value = 0;

	ft_putnbr(ft_strlen_eof(*file));
	write(1, "\t", 1);
	

	if (!(*line = ft_substr(*file, 0, endl)) || !ft_strlen_eof(*file) || !endl
		|| !(aux = ft_substr(*file, endl + 1, ft_strlen_eof(*file) - endl - 1)))
		return (-1);
	ft_free((void**)file);
	*file = aux;
	return (rtrn_value);
}

static int	put_line(char **line, char **file, char **buf, size_t endl)
{
	int		rtrn_value;
	size_t	file_len;
	size_t	buf_len;

	write(1, ">>>> Entrou em put_line!\n", 25);
	
	rtrn_value = 1;
	if ((*buf)[endl] == EOF)
		rtrn_value = 0;

	ft_putnbr(endl);
	write(1, "\t", 1);

	file_len = ft_strlen_eof(*file);
	buf_len = endl;
	if (!(*line = (char*)malloc(file_len + buf_len + 1)))
		return (-1);
	ft_memmove(*line, *file, file_len);
	ft_memmove(&((*line)[file_len]), *buf, buf_len);
	(*line)[file_len + buf_len] = '\0';
	ft_free((void**)file);
	if (endl < ft_strlen_eof(*buf))
		*file = ft_substr(*buf, endl + 1, ft_strlen_eof(*buf) - endl - 1);
	ft_free((void**)buf);
	return (rtrn_value);
}

static int	store_file_buf(char **file, char **buf)
{
	char	*aux;
	size_t	file_len;
	size_t	buf_len;

	write(1, ">>>> Entrou em store_file_buf!\n", 31);
	
	file_len = ft_strlen_eof(*file);
	buf_len = ft_strlen_eof(*buf);
	if (!(aux = (char*)malloc(file_len + buf_len + 1)))
		return (0);
	ft_memmove(aux, *file, file_len);
	ft_memmove(&(aux[file_len]), *buf, buf_len + 1);
	ft_free((void**)file);
	ft_free((void**)buf);
	*file = aux;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*files[OPEN_MAX];
	char			*buf;
	ssize_t			endl;
	ssize_t			buf_size;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (files[fd] && ((endl = find_char(files[fd], '\n')) >= 0 ||
				(endl = find_char(files[fd], EOF)) >= 0))
		return (put_line_file(line, &(files[fd]), (size_t)endl));
	if (!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char)))
				|| ((buf_size = read(fd, buf, BUFFER_SIZE)) < 0))
		return (-1);
	buf[buf_size] = buf_size < BUFFER_SIZE ? '\0' : EOF;
	if ((endl = find_char(buf, '\n')) >= 0 || (endl =
					find_char(buf, EOF)) >= 0)
		return (put_line(line, &(files[fd]), &buf, (size_t)endl));
	if (!store_file_buf(&(files[fd]), &buf))
		return (-1);
	return (get_next_line(fd, line));
}
