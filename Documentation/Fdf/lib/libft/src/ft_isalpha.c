/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:19:54 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:34:27 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}

/* int main(void)
{
    int a = 65;
    int b = 64;
    int c = 0;
    int d = 24;
    int e = 89;
    int f = 90;
    int g = 91;
    int h = 96;
    int i = 97;
    int j = 122;
    int k = 123;
    int l = 127;

    printf("for int = '%c', ft_isalpha returns '%d'\n", a, ft_isalpha(a));
    printf("for int = '%c', ft_isalpha returns '%d'\n", b, ft_isalpha(b));
    printf("for int = '%c', ft_isalpha returns '%d'\n", c, ft_isalpha(c));
    printf("for int = '%c', ft_isalpha returns '%d'\n", d, ft_isalpha(d));
    printf("for int = '%c', ft_isalpha returns '%d'\n", e, ft_isalpha(e));
    printf("for int = '%c', ft_isalpha returns '%d'\n", f, ft_isalpha(f));
    printf("for int = '%c', ft_isalpha returns '%d'\n", g, ft_isalpha(g));
    printf("for int = '%c', ft_isalpha returns '%d'\n", h, ft_isalpha(h));
    printf("for int = '%c', ft_isalpha returns '%d'\n", i, ft_isalpha(i));
    printf("for int = '%c', ft_isalpha returns '%d'\n", j, ft_isalpha(j));
    printf("for int = '%c', ft_isalpha returns '%d'\n", k, ft_isalpha(k));
    printf("for int = '%c', ft_isalpha returns '%d'\n", l, ft_isalpha(l));

    return (0);
} */