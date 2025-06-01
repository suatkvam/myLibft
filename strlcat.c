/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:49:01 by akivam            #+#    #+#             */
/*   Updated: 2025/06/01 15:50:12 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		src_len;
	int		dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	while ((src[i] != '\0') && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i += 1;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
