/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:33:18 by akivam            #+#    #+#             */
/*   Updated: 2025/06/11 13:17:50 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		if(sign == 1 && num > 2147483647)
			return (-1);
		if(sign == -1 && num > -2147483648)
			return (0);
		i++;
	}
	return (num * sign);
}
