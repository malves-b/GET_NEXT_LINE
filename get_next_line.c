/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:22:27 by malves-b          #+#    #+#             */
/*   Updated: 2024/04/30 18:13:36 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_aux(int fd, char *buffer, char *backup)
{
	int		i;
	char	*aux;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!backup)
			backup = ft_strdup("");
		aux = backup;
		backup = ft_strjoin(aux, buffer);
		free(aux);
		aux = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (backup);
}

/* -------------------------------------------------------------------------- */

char	*ft_exclude_line(char *str)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[1] == '\0')
		return (0);
	ret = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*ret == '\0')
	{
		free(ret);
		ret = NULL;
	}
	str[i + 1] = '\0';
	return (ret);
}

/* -------------------------------------------------------------------------- */

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = get_next_line_aux(fd, buffer, backup);
	free (buffer);
	buffer = NULL;
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (0);
	}
	backup = ft_exclude_line(line);
	return (line);
}


#include <fcntl.h>

int main(){

    char    *path;
	char	*line;
    int fd;
	int i = 0;

    path = "/home/malves-b/sgoinfre/get_next_line/texto.txt";
    fd = open(path, O_RDONLY);

	while (i <= 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		puts("");
		i++;
	}
}
