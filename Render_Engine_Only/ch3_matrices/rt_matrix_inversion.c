/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_inversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:45:04 by pberset           #+#    #+#             */
/*   Updated: 2025/05/05 17:44:04 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

float	rt_determinant(t_matrix m)
{
	float	det;
	int		i;

	if (m.rows == 2)
		det = m.cell[0][0] * m.cell[1][1] - m.cell[0][1] * m.cell[1][0];
	else
	{
		i = 0;
		det = 0;
		while (i < m.columns)
		{
			det = det + m.cell[0][i] * rt_cofactor(m, 0, i);
			i++;
		}
	}
	return (det);
}

void	rt_sub_matrix(t_matrix m, int row, int col, t_matrix *sub)
{
	int			i;
	int			j;
	int			k;
	int			l;

	sub->rows = m.rows - 1;
	sub->columns = m.columns - 1;
	i = -1;
	k = 0;
	while (++i < m.rows)
	{
		if (i == row)
			continue;
		j = -1;
		l = 0;
		while (++j < m.columns)
		{
			if (j == col)
				continue;
			sub->cell[k][l] = m.cell[i][j];
			l++;
		}
		k++;
	}
}

float	rt_minor(t_matrix m, int row, int col)
{
	float		minor;
	t_matrix	sub;

	rt_sub_matrix(m, row, col, &sub);
	minor = rt_determinant(sub);
	return (minor);
}

float	rt_cofactor(t_matrix m, int row, int col)
{
	float	cofactor;

	cofactor = rt_minor(m, row, col);
	if ((row + col) % 2)
		cofactor = -cofactor;
	return (cofactor);
}

void	rt_inversion(t_matrix m, t_matrix *invert)
{
	float		det;
	float		cofactor;
	int			i;
	int			j;

	errno = 0;
	det = rt_determinant(m);
	if (fabs(det) < EPSILON)
	{
		errno = ENOTINVERTIBLE;
		*invert = rt_identity_matrix();
		return ;
	}
	invert->rows = m.rows;
	invert->columns = m.columns;
	i = -1;
	while (++i < m.rows)
	{
		j = -1;
		while (++j < m.columns)
		{
			cofactor = rt_cofactor(m, i, j);
			invert->cell[j][i] = cofactor / det;
		}
	}
}
