/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:08:39 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 12:07:11 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char			*buf;
	static char		next_lines[BUFFER_SIZE];
	static int		read_ret = BUFFER_SIZE;
	struct s_result	res;

	if (fd == -1)
		return (NULL);
	res.line = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (!ft_strlen(next_lines))
		read_ret = ft_read(fd, buf, read_ret);
	else
		ft_strlcpy(buf, next_lines, BUFFER_SIZE + 1);
	res = ft_fill_line(buf, NULL, read_ret, fd);
	read_ret = res.read_ret;
	ft_next_lines(next_lines, buf);
	free(buf);
	if (read_ret == -1)
	{
		ft_free((void **)&res.line);
		return (NULL);
	}
	return (res.line);
}

/* fills the line with characters from the buffer
* if the buffer doesn't contain a newline character then, 
reads again into the buffer,
* and repeats the operations if no newline.
* If a newline character is found in the buffer buf, 
* the characters leading to that
* newline (including the newline) are added to the line 
* returns the line, buffer, and last read return value */
struct s_result	ft_fill_line(char *buf, char *line, int read_ret, int fd)
{
	struct s_result	res;

	if (read_ret > 0)
	{
		while (ft_end_of_line(buf) == 0 && ft_strlen(buf))
		{
			line = ft_add_string(buf, ft_strlen(buf), line);
			read_ret = ft_read(fd, buf, read_ret);
			if (read_ret == -1)
				break ;
		}
		if (ft_end_of_line(buf))
			line = ft_add_string(buf, ft_end_of_line(buf), line);
	}
	res.read_ret = read_ret;
	res.line = line;
	res.buf = buf;
	return (res);
}

/* ft_strjoin adaptation 
* Allocates enough space for our two strings and 
* concatenates them in the new string.
* free() is executed either in our ft_fill_line 
* while() loop, or in the main if this is 
* the last ft_add_string call by the get_next_line function */
char	*ft_add_string(char *addition, unsigned int addition_count, char *base)
{
	char			*output;
	char			*temp;
	unsigned int	i;
	unsigned int	base_length;

	temp = NULL;
	base_length = ft_strlen(base);
	if (base)
		temp = base;
	output = malloc((base_length + addition_count + 2) * sizeof(char));
	if (!output)
		return (0);
	else
	{
		i = 0;
		while (i++ < base_length)
			output[i - 1] = base[i - 1];
		i = 0;
		while (i++ < addition_count)
			output[base_length + i - 1] = addition[i - 1];
		output[base_length + i - 1] = '\0';
	}
	ft_free((void **)&temp);
	return (output);
}

void	ft_free(void **temp)
{
	if (*temp)
	{
		free(*temp);
		*temp = NULL;
	}
}

/* attempts to read BUFFER_SIZE characters into the 
* buffer buf, null-terminates buf, and returns the number of characters read 
* in case of a read error, fills the buffer with '\0' characters */
int	ft_read(int fd, char *buf, int read_ret)
{
	read_ret = read(fd, buf, BUFFER_SIZE);
	if (read_ret > -1)
		buf[read_ret] = '\0';
	if (read_ret == -1)
		ft_fill_char(buf, '\0');
	return (read_ret);
}

// #include <fcntl.h>
// int main()
// {
// 	char *path;
// 	path = "/Users/fallan/42/get_next_line/examples/example2.txt";

// 	int fd = open(path, O_RDONLY);
// 	fd = open(path, O_RDONLY);

// 	char	*ret_value;
// 	ret_value = NULL;

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL)
// 		printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	close(fd);
// 	return (0);
// }
