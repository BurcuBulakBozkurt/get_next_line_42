/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbulak-b <bbulak-b@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:48:29 by bbulak-b          #+#    #+#             */
/*   Updated: 2023/08/07 10:54:24 by bbulak-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text(int fd, char *buftxt)
{
	char	*temp;
	int		read_bytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	read_bytes = 1;
	while (!ft_strchr(buftxt, '\n') && read_bytes != 0) //It reads the contents of the file no matter how many buffer_size is, that was the important question in the project. 
		//The difference is; how many times it loops. If buffer_size is large enough, it can read it at once, if not, it loops several times.
	{
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp);
			free(buftxt);
			return (0);
		}
		temp[read_bytes] = '\0';
		buftxt = ft_strjoin(buftxt, temp);
	}
	free(temp);
	return (buftxt);
}

char	*get_next_line(int fd)
{
	static char	*buftxt; 
	//If it was just char*, it would be reset after exiting the function, since it is static, it keeps the result in memory. 
	//We want to keep the result after the end of the line (/n) in memory because we want to print it in the future, so we write use static char*.
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buftxt = ft_get_text(fd, buftxt);
	if (!buftxt)
		return (0);
	line = ft_strtrim_l(buftxt);
	buftxt = ft_strtrim_r(buftxt);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int	i;
	int	fd;

	i = 0;
	fd = open("docs/new.txt", O_RDONLY);
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
