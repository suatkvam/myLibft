/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:05:45 by akivam            #+#    #+#             */
/*   Updated: 2025/05/29 19:12:14 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
/* This function checks whether the given value*/
/*is a printable ASCII character.*/
/* Returns 1 if the character*/
/*is between 32 and 126 (inclusive), otherwise returns 0.*/
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
// int main(int argc, char const *argv[])
// {
// 	printf("%d",ft_isprint("\a"));
// 	return 0;
// }
