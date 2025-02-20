/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:46 by fallan            #+#    #+#             */
/*   Updated: 2024/04/04 16:31:23 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

/* looks at #BUFFER_SIZE characters in a string: 
	- if those characters contain an '\n', 
	returns the index of '\n' + 1 (in case '\n' is at index 0)
	- otherwise, returns 0 */
unsigned int	ft_end_of_line(char *buf)
{
	unsigned int	i;

	i = 0;
	while (i < (BUFFER_SIZE) && buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		return (i + 1);
	else
		return (0);
}

/* adapted from ft_bzero (see libft)
takes a string s, creates a pointer str to it of length ft_strlen(s), 
then fills that pointer with '\0', and return it */
void	*ft_fill_char(void *s, char c)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *) s;
	i = 0;
	if (str)
	{
		while (i < (BUFFER_SIZE) && str[i])
		{
			str[i] = c;
			i++;
		}
	}
	if (str[i])
		str[i] = '\0';
	return (str);
}

char	*ft_next_lines(char *dst, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\n' && src[i] && i < (BUFFER_SIZE))
		i++;
	if (!src[i] || i == (BUFFER_SIZE))
		return (ft_fill_char(dst, '\0'));
	else if (src[i++] == '\n')
	{
		if (!src[i])
			return (ft_fill_char(dst, '\0'));
		else
		{
			while (src[i + j] && i + j < (BUFFER_SIZE))
			{
				dst[j] = src[i + j];
				j++;
			}
			dst[j] = '\0';
		}
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* adapted for str == NULL*/
size_t	ft_strlen(const char *str)
{
	int	length;

	if (!str)
		return (0);
	length = 0;
	if (str)
	{
		while (str[length] != 0)
			length++;
	}
	return (length);
}
