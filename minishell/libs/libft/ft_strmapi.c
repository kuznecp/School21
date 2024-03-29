/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:28:41 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 21:28:41 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
s - a pointer to a string to which you want to apply f.
f is a pointer to a function for processing elements of string s.

Returned values:
The function returns a pointer to a string whose elements have been processed
function f. NULL is returned if memory allocation failed.

Description:
The function sequentially applies the passed function f to the elements of the
string s and returns a pointer to a new line with processed items. If not
managed to allocate memory for new row returned NULL.
*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (res == NULL)
		return (res);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
