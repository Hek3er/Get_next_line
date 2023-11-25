/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:18:41 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/25 23:53:38 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	join_and_free(char **buffer, char *buf)
{
	char	*temp;

	temp = ft_join(*buffer, buf);
	free(*buffer);
	*buffer = temp;
}

char	*read_from_line(char *buffer, int fd)
{
	int		r;
	char	*buf;

	r = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r == -1)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buf[r] = '\0';
		join_and_free(&buffer, buf);
		if (n_search(buffer))
			break ;
	}
	return (free(buf), buffer);
}

char	*add_to_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*delete_newline(char *buffer)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	return (free(buffer), new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_from_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = add_to_line(buffer);
	if (line[0] == '\0' && buffer[0] == '\0')
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	buffer = delete_newline(buffer);
	return (line);
}

int main()
{
	int fd;
	char *str;
	
	fd = open("41_no_nl", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if(!str)
			break;
		printf("%s", str);
	}
}