/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:53:12 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 20:53:12 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "error_msgs.h"
#include "libft.h"
#include "builtins.h"
#include "minishell.h"
#include "actions_handler.h"

static int	is_number(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

static int	close_fd(int fd)
{
	if (fd)
		close(fd);
	return (0);
}

static int	check_exitcode(char **args)
{
	if (!args[1])
		return (0);
	else
	{
		if (is_number(args[1]) && !args[2])
			return (ft_atoi(args[1]) % 256);
		else if (!is_number(args[1]))
		{
			print_err(MSG_ERR_EXIT_NUM, args[1], 0);
			return (2);
		}
		else
		{
			print_err(MSG_ERR_EXIT_ARGS, NULL, 0);
			return (1);
		}
		return (DO_EXIT);
	}
}

int	do_exit(t_action action, char ***env)
{
	if (action.pipe_out || action.pipe_in)
		return (close_fd(action.pipe_out) + check_exitcode(action.exec.argv));
	printf("exit\n");
	if (!(action.exec.argv[1]))
		return (DO_EXIT);
	else
	{
		if (is_number(action.exec.argv[1]) && !(action.exec.argv[2]))
			set_env("LES", action.exec.argv[1], env);
		else if (!is_number(action.exec.argv[1]))
		{
			print_err(MSG_ERR_EXIT_NUM, action.exec.argv[1], 0);
			set_env("LES", "2", env);
		}
		else
		{
			print_err(MSG_ERR_EXIT_ARGS, NULL, 0);
			return (1);
		}
		return (DO_EXIT);
	}
}
