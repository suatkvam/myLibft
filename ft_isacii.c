/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isacii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:53:24 by akivam            #+#    #+#             */
/*   Updated: 2025/05/30 10:42:14 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 || c <= 127)
		return (1);
	return (0);
}
// int main(int argc, char const *argv[])
// {
// 	printf("%d",ft_isascii(128));
// 	return 0;
// }
