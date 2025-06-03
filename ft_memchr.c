/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 08:49:17 by akivam            #+#    #+#             */
/*   Updated: 2025/06/01 08:54:13 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s1;
	while (str[i])
	{
		if (str[i] == c && i < n)
			return (str + i);
		i++;
	}
	return (NULL);
}
