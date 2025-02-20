/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:19:58 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:34:24 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}

/* int main()
{
    int a = 65;
    int b = 64;
    int c = 0;
    int d = 49;
    int e = 89;
    int f = 90;
    int g = 91;
    int h = 8;
    int i = 97;
    int j = 122;
    int k = 123;
    int l = 57;

    printf("for int = '%c', ft_isalnum returns '%d'\n", a, ft_isalnum(a));
    printf("for int = '%c', ft_isalnum returns '%d'\n", b, ft_isalnum(b));
    printf("for int = '%c', ft_isalnum returns '%d'\n", c, ft_isalnum(c));
    printf("for int = '%c', ft_isalnum returns '%d'\n", d, ft_isalnum(d));
    printf("for int = '%c', ft_isalnum returns '%d'\n", e, ft_isalnum(e));
    printf("for int = '%c', ft_isalnum returns '%d'\n", f, ft_isalnum(f));
    printf("for int = '%c', ft_isalnum returns '%d'\n", g, ft_isalnum(g));
    printf("for int = '%c', ft_isalnum returns '%d'\n", h, ft_isalnum(h));
    printf("for int = '%c', ft_isalnum returns '%d'\n", i, ft_isalnum(i));
    printf("for int = '%c', ft_isalnum returns '%d'\n", j, ft_isalnum(j));
    printf("for int = '%c', ft_isalnum returns '%d'\n", k, ft_isalnum(k));
    printf("for int = '%c', ft_isalnum returns '%d'\n", l, ft_isalnum(l));
    
    return(0);
} */