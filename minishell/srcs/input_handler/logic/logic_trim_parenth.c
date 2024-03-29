/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_trim_parenth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:53:54 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 20:53:55 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "input_handler.h"
#include "libft.h"

static char	*open_parenthis(char **str)
{
	char	*new;
	size_t	i;

	i = find_paired_parenth(*str, 1, 0, 0);
	if (ft_strlen(*str) != i + 1)
		return (*str);
	new = ft_substr(*str, 1, ft_strlen(*str) - 2);
	if (new == NULL)
		return (*str);
	free(*str);
	return (new);
}

char	*trim_and_update_cmdstr(char **cmd)
{
	char	*tmp;

	tmp = ft_strtrim(*cmd, " \t");
	if (tmp)
	{
		free(*cmd);
		*cmd = tmp;
	}
	while ((*cmd)[0] == open_parenth
		&& ft_strlen(*cmd) == find_paired_parenth(*cmd, 1, 0, 0) + 1)
	{
		if ((*cmd)[ft_strlen(*cmd) - 1] == close_parenth)
			*cmd = open_parenthis(cmd);
		tmp = ft_strtrim(*cmd, " \t");
		if (tmp)
		{
			free(*cmd);
			*cmd = tmp;
		}
	}
	return (*cmd);
}
