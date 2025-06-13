/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:40:24 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:23:21 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*output;
	char	*output_start;

	output = (char *)ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (errno)
	{
		perror("ft_strdup");
		return (NULL);
	}
	output_start = output;
	while (*s1)
	{
		*output = *s1;
		output++;
		s1++;
	}
	*output = 0;
	return (output_start);
}
