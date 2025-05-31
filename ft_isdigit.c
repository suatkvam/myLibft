/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:01:04 by akivam            #+#    #+#             */
/*   Updated: 2025/05/30 10:42:06 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int main(int argc, char const *argv[])
{
	int a = ' ';
	int b = '0';
	int c = '9';
	int d = 'a';
	int e = 'b';
	int f = '10';
	printf("%d",ft_isdigit(a));
	printf("%d",ft_isdigit(b));
	printf("%d",ft_isdigit(c));
	printf("%d",ft_isdigit(d));
	printf("%d",ft_isdigit(e));
	printf("%d",ft_isdigit(f));
	return 0;
}
*/
