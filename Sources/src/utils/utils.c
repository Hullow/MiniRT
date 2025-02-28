/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:13:54 by fallan            #+#    #+#             */
/*   Updated: 2025/02/28 15:10:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

/* prints the message corresponding to the error type (see enum in header), 
and returns -1 */
void	*handle_error(t_error error_type)
{
	if (error_type == NULL_INPUT)
	{
		printf("input is NULL - couldn't perform operation\n");
		return (NULL);
	}
	else if (error_type == MALLOC_FAIL)
	{
		printf("malloc fail\n");
		return (NULL);
	}
	else if (error_type == INVALID_MATRIX_SIZE)
	{
		printf("invalid matrix size\n");
		return (NULL);
	}
	return (0);
}