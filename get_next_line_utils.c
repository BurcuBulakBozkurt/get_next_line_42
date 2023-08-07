/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbulak-b <bbulak-b@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:52:01 by bbulak-b          #+#    #+#             */
/*   Updated: 2023/08/07 11:02:07 by bbulak-b         ###   ########.fr       */
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

char	*ft_strjoin(char *buftxt, char *temp)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!buftxt)
	{
		buftxt = malloc(sizeof(char) * 1);
		buftxt[0] = '\0';
	}
	new_str = malloc(sizeof(char) * (ft_strlen(buftxt) + ft_strlen(temp) + 1));
	if (!new_str)
		return (0);
	while (buftxt[++i])
		new_str[i] = buftxt[i];
	while (temp[++j])
		new_str[j + i] = temp[j];
	new_str[i + j] = '\0';
	free(buftxt);
	return (new_str);
}

char	*ft_strtrim_l(char *buftxt)
{
	char	*final_line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!buftxt[i])
		return (0);
	while (buftxt[i] && buftxt[i] != '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 2));
	if (!final_line)
		return (0);
	j = -1;
	while (++j <= i)
		final_line[j] = buftxt[j];
	final_line[j] = '\0';
	return (final_line);
}

char	*ft_strtrim_r(char *buftxt)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	i = 0;
	while (buftxt[i] && buftxt[i] != '\n')
		i++;
	if (!buftxt[i])
	{
		free(buftxt);
		return (0);
	}
	next_line = malloc(sizeof(char) * (ft_strlen(buftxt) - i));
	if (!next_line)
		return (0);
	j = -1;
	while (++i < ft_strlen(buftxt))
		next_line[++j] = buftxt[i];
	next_line[++j] = '\0';
	free(buftxt);
	return (next_line);
}
