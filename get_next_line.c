/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satakrur <satakrur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:26:07 by satakrur          #+#    #+#             */
/*   Updated: 2025/01/22 19:30:27 by satakrur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_content(int fd)
{
	int			bytesread;
	char		*buff;
	static char	*content = NULL;
	char		*temp;

	bytesread = 1;
	while (bytesread > 0)
	{
		buff = (char *)malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return (NULL);
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(buff);
			break ;
		}
		// if (bytesread == -1)
		// {
		// 	free(content);
		// 	content = NULL;
		// 	return (free(buff), NULL);
		// }
		buff[bytesread] = '\0';
		temp = ft_strjoin(content, buff);
		free (content);
		content = temp;
		free(buff);
		if (content == NULL)
			return (NULL);
	}
	
	return (content);
}

char	*ft_get_line(char *content)
{
	static int	i;
	int			k;
	int			j;
	char		*line;

	k = i;
	if (content == NULL || content[i] == '\0')
		return (NULL);
	while (content[i] != '\0' && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i - k + 1));
	if (!line)
		return (NULL);
	j = 0;
	if (k == i)
		return (free(line), NULL);
	while (k < i)
		line[j++] = content[k++];
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*content;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	//content = NULL;
	content = get_content(fd);
	if (!content)
		return (NULL);
	line = ft_get_line(content);
	if (line == NULL)
	{
		free(content);
		content = NULL;
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;
// 		printf("%s", str);
// 		free(str);
// 	}
// 	close(fd);
// }
