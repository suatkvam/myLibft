/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 08:51:40 by akivam            #+#    #+#             */
/*   Updated: 2025/05/28 09:08:40 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function checks whether the given value is an alphabetic character. */
/* Returns 1 if the value is an alphabetic character, otherwise returns 0. */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
int main(int argc, char const *argv[])
{
	int a = 'A';
	int b = 'Z';
	int c = 'a';
	int d = 'z';
	int e = '0';
	int f = ' ';
	
	printf("%d",ft_isdigit(a));
	printf("%d",ft_isdigit(b));
	printf("%d",ft_isdigit(c));
	printf("%d",ft_isdigit(d));
	printf("%d",ft_isdigit(e));
	printf("%d",ft_isdigit(f));
	return 0;
}
*/