/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:29:19 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 21:29:19 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
int c - the code of the character to be converted to lowercase.

Return value:
Returns the lowercase equivalent of c if
c is an uppercase letter. Otherwise, c is returned unchanged.

Description:
Checks if a character is a letter, if so, converts to lowercase.
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
