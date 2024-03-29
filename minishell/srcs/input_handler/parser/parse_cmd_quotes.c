/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:54:55 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 20:54:55 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline int	is_open_quotes(char *cmd, t_iter *iter)
{
	if (cmd[iter->i] == quote || cmd[iter->i] == single_quote)
	{
		if (iter->i == 0)
			return (true);
		else if (escaped(cmd, iter->i) == false)
			return (true);
	}
	return (false);
}

inline void	do_check_quotes(char *cmd, t_iter *iter)
{
	char	*pchar;

	if (iter->i != iter->k)
		return ;
	if (is_open_quotes(cmd, iter))
	{
		pchar = &cmd[iter->i];
		iter->k = iter->i + 1;
		while (pchar)
		{
			pchar = ft_strchr(cmd + iter->k, *pchar);
			if (pchar)
			{
				iter->k = pchar - cmd + 1;
				if (cmd[iter->i] == quote && escaped(cmd, pchar - cmd))
					continue ;
				iter->in_qoutes = *pchar;
				return ;
			}
		}
	}
	iter->k = iter->i + 1;
	iter->in_qoutes = false;
}
