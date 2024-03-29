/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:55:11 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 20:55:12 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

#include "libft.h"
#include "bool.h"
#include "mesages.h"
#include "error_msgs.h"
#include "actions_handler.h"
#include "input_handler.h"
#include "minishell.h"

inline int	check_g_interrupt(void)
{
	if (g_interrupt)
		rl_done = true;
	return (0);
}

static inline void	do_update_cmd(char **cmd)
{
	char	*tmp;
	char	*line;

	set_signals(3, 0);
	rl_event_hook = check_g_interrupt;
	line = readline(MSG_RL_SUBINPUT);
	if (line != NULL)
	{
		tmp = *cmd;
		*cmd = ft_strjoinchr(*cmd, space);
		free(tmp);
		tmp = *cmd;
		*cmd = ft_strjoin(*cmd, line);
		free(tmp);
		free(line);
	}
	rl_event_hook = NULL;
	set_signals(0, 1);
}

static inline int	do_append_cmd(char **cmd)
{
	int	i;

	if (cmd == NULL || *cmd == NULL)
		return (unsuccess);
	i = ft_strlen(*cmd);
	while (--i >= 0 && (*cmd)[i] != ends && (*cmd)[i] == space
		&& escaped(*cmd, i) == false)
		(*cmd)[i] = ends;
	i = 0;
	while (**cmd != ends && **cmd == space && escaped(*cmd, i) == false)
	{
		i++;
		*cmd += 1;
	}
	if (**cmd == pipes)
	{
		print_err(MSG_ERR_SYNATX, NULL, false);
		return (unsuccess);
	}
	if (**cmd && (*cmd)[ft_strlen(*cmd) - 1] == pipes)
		do_update_cmd(cmd);
	if (*cmd)
		return (success);
	return (unsuccess);
}

static inline void	init(t_actions *actions)
{
	actions->len = 0;
	actions->pipes.len = 0;
	actions->pipes.item = NULL;
	actions->item = NULL;
}

int	input_handler(char **cmd, char ***env)
{
	int			res;
	t_node		*node;
	t_actions	actions;

	if (do_append_cmd(cmd) == unsuccess)
		return (-1);
	res = check_cmd_sequenses(*cmd);
	if (!res)
		return (2);
	init(&actions);
	*cmd = trim_and_update_cmdstr(cmd);
	if (has_logical_operators(*cmd, 0, 0, 0))
	{
		node = extract_node(cmd);
		res = exec_node(node, env);
		if (!node)
			return (res);
		free(node->left);
		free(node->right);
		free(node);
		return (res);
	}
	return (do_actions(do_actions_build(&actions, *cmd, env), env));
}
