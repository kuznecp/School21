/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:28:33 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 21:28:33 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
str is a pointer to the string whose length needs to be calculated.

Return value:
The number of characters in the string before the first occurrence of the
end-of-line character. If str is NULL will returns NULL.

Description:
The strlen function calculates the number of characters in a string before the
first occurrence end-of-line character. In this case, the end-of-line character
is not included in the counted characters.
*/
size_t	ft_strlen(const char *str)
{
	size_t	res;

	res = 0;
	while (str[res] != '\0')
	{
		res++;
	}
	return (res);
}
