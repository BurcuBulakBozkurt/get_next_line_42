/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbulak-b <bbulak-b@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:52:01 by bbulak-b          #+#    #+#             */
/*   Updated: 2023/07/26 10:52:11 by bbulak-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin(char *bufftxt, char *temp)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!bufftxt)
	{
		bufftxt = malloc(sizeof(char) * 1);
		bufftxt[0] = '\0';
	}
	new_str = malloc(sizeof(char) * (ft_strlen(bufftxt) + ft_strlen(temp) + 1));
	if (!new_str)
		return (0);
	while (bufftxt[++i])
		new_str[i] = bufftxt[i];
	while (temp[++j])
		new_str[j + i] = temp[j];
	new_str[i + j] = '\0';
	free(bufftxt);
	return (new_str);
}

char	*ft_strtrim_l(char *bufftxt)
{
	char	*final_line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!bufftxt[i])
		return (0);
	while (bufftxt[i] && bufftxt[i] != '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 2));
	if (!bufftxt)
		return (0);
	j = -1;
	while (++j <= i)
		final_line[j] = bufftxt[j];
	final_line[j] = '\0';
	return (final_line);
}

char	*ft_strtrim_r(char *bufftxt)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	i = 0;
	while (bufftxt[i] && bufftxt[i] != '\n')
		i++;
	if (!bufftxt[i])
	{
		free(bufftxt);
		return (0);
	}
	next_line = malloc(sizeof(char) * (ft_strlen(bufftxt) - i));
	if (!bufftxt)
		return (0);
	j = -1;
	while (++i < ft_strlen(bufftxt))
		next_line[++j] = bufftxt[i];
	next_line[++j] = '\0';
	free(bufftxt);
	return (next_line);
}
