/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:16:06 by akivam            #+#    #+#             */
/*   Updated: 2025/05/29 18:35:43 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*This function checks whether*/
/*the given value is a digit or an alphabetic character.*/
/*Returns 1 if the value is*/
/*between '0'-'9' or 'A'-'Z'/'a'-'z', otherwise returns 0.*/
int	ft_isalnum(int c)
{
	return(ft_isalpha(c) || ft_isdigit(c));
}
