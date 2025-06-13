/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:00:48 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:26:40 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*output;

	i = 0;
	output = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (errno)
	{
		perror("ft_strmapi");
		return (NULL);
	}
	while (s[i])
	{
		output[i] = (unsigned char)f(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
