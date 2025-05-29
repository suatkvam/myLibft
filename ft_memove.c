/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:58:06 by akivam            #+#    #+#             */
/*   Updated: 2025/05/29 12:01:54 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libft.h>
/*
ft_memmove - Copy 'n' bytes from memory area 'src' to memory area 'dest'.
The memory areas may overlap: copying is done in a non-destructive manner.

Parameters:
  dest - pointer to the destination memory area
  src  - pointer to the source memory area
  n    - number of bytes to copy

Returns:
  Pointer to the destination memory area 'dest'.

Behavior:
  If 'dest' is at a lower memory address than 'src', bytes are copied
  forward from the beginning to avoid overwriting source bytes.
  If 'dest' is at a higher memory address than 'src', bytes are copied
  backward from the end to prevent overlap issues.

 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	i = 0;
	tmp_src = src;
	tmp_dst = dest;
	if (n == 0 || tmp_src == tmp_dst)
		return (dest);
	if (tmp_src > tmp_dst)
	{
		ft_memset(tmp_dst, tmp_src, n);
	}
	if (tmp_dst > tmp_src)
	{
		while (i >= 0)
		{
			tmp_dst[i - 1] = tmp_src[i - 1];
			if (i == 0)
				break ;
			i = i - 1;
		}
	}
	return (dest);
}
