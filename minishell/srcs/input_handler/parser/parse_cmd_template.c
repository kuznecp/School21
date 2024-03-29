/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_template.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:55:01 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 20:55:02 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline int	do_check_quotes_or_break(
	char *cmd, int *i, char **quote_type)
{
	if (cmd[*i] == quote || cmd[*i] == single_quote)
	{
		if (*quote_type)
		{
			if (**quote_type == single_quote && cmd[*i] == **quote_type)
				*quote_type = NULL;
			else if (cmd[*i] == **quote_type && escaped(cmd, *i) == false)
				*quote_type = NULL;
		}
		else if (*quote_type == NULL)
			*quote_type = cmd + *i;
		return (false);
	}
	if (cmd[*i] == space && escaped(cmd, *i) == false && *quote_type == NULL)
		return (true);
	return (false);
}

static inline void	find_start(char *cmd, char open_quote, t_extract *args)
{
	char	*quote_type;

	quote_type = NULL;
	args->start = args->pchar - cmd;
	if (open_quote)
	{
		while (args->start >= args->prev_end)
		{
			if (cmd[args->start] == open_quote
				&& escaped(cmd, args->start) == false)
				break ;
			args->start--;
		}
		return ;
	}
	while (args->start > args->prev_end)
	{
		if (do_check_quotes_or_break(cmd, &args->start, &quote_type))
			break ;
		args->start--;
	}
	if (cmd[args->start] == space)
		args->start++;
}

static inline void	find_end(char *cmd, char open_quote, t_extract *args)
{
	char	*quote_type;

	quote_type = NULL;
	args->end = args->pchar - cmd;
	if (open_quote)
	{
		while (cmd[args->end] != ends)
		{
			if (cmd[args->end++] == open_quote
				&& escaped(cmd, args->end) == false)
				break ;
		}
		return ;
	}
	while (cmd[args->end] != ends)
	{
		if (do_check_quotes_or_break(cmd, &args->end, &quote_type))
			break ;
		args->end++;
	}
}

inline void	get_template_border(char *cmd, t_extract *args)
{
	char	open_quote;

	open_quote = has_opened_quotes(cmd, args->prev_end, args->pchar - cmd);
	find_start(cmd, open_quote, args);
	find_end(cmd, open_quote, args);
}
