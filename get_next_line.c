/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbulak-b <bbulak-b@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:48:29 by bbulak-b          #+#    #+#             */
/*   Updated: 2023/07/26 13:35:11 by bbulak-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text(int fd, char *bufftxt)
{
	char	*temp;
	int		rbytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	rbytes = 1;
	while (!ft_strchr(bufftxt, '\n') && rbytes != 0)
	{
		rbytes = read(fd, temp, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free(temp);
			free(bufftxt);
			return (0);
		}
		temp[rbytes] = '\0';
		bufftxt = ft_strjoin(bufftxt, temp);
	}
	free(temp);
	return (bufftxt);
}

char	*get_next_line(int fd)
{
	static char	*bufftxt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bufftxt = ft_get_text(fd, bufftxt);
	if (!bufftxt)
		return (0);
	line = ft_strtrim_l(bufftxt);
	bufftxt = ft_strtrim_r(bufftxt);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int	i;
	int	fd;
	
	i = 0;
	fd = open("docs/new.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
