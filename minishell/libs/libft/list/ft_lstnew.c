/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:25:40 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 21:25:40 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Arguments:
content - a pointer to the data that will be placed in the content field.

Returned value:
Pointer to a new item in the list.

Description:
The function gets a pointer to the data content, creates a new list item,
puts the passed data into the content field of the element and returns a pointer
to a new list item. If it was not possible to allocate memory for a new element,
NULL is returned.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new)
	{
		new->next = NULL;
		new->content = content;
	}
	return (new);
}
