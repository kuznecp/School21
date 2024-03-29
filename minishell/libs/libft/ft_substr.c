/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:29:09 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 21:29:10 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
s is a pointer to the original string.
start - the character index in the source line from which to start copying.
len is the maximum length to copy.

Return value:
Returns a pointer to the copied substring, or NULL if copying is not
succeeded.

Description:
The function copies a substring from the original string s starting at index
start and length at most len. On success, returns a pointer to the copied
substring.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		subs = (char *)ft_calloc(ft_strlen(s + start) + 1, sizeof(char));
	else
		subs = (char *)ft_calloc(len + 1, sizeof(char));
	if (subs == NULL)
		return (NULL);
	if (ft_strlcpy(subs, s + start, len + 1))
		return (subs);
	free(subs);
	return (NULL);
}
