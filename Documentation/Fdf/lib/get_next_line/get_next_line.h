/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:40 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 11:59:50 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42

# endif

struct	s_result {
	int		read_ret;
	char	*line;
	char	*buf;
};

char			*get_next_line(int fd);
struct s_result	ft_fill_line(char *buf, char *line, int read_ret, int fd);
char			*ft_add_string(char *addition, \
unsigned int end_of_line, char *base);
int				ft_read(int fd, char *buf, int read_ret);
void			ft_free(void **temp);
unsigned int	ft_end_of_line(char *buf);
void			*ft_fill_char(void *s, char c);
char			*ft_next_lines(char *dst, char *src);

#endif
