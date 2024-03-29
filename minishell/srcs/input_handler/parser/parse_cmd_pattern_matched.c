/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:54:50 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 20:54:51 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline void	pattern_matching_get_next(char **next, char *templated_str)
{
	while (**next != ends
		&& ft_strncmp(*next, templated_str, ft_strlen(templated_str)) != 0)
		(*next)++;
}

inline int	pattern_matched(t_select *args)
{
	if (args->d_name == NULL)
		return (false);
	if (args->direction == single_asterisk && *args->d_name != dot)
		return (true);
	if (args->direction == all_inn_all)
		return (do_match_all_inn_all(args));
	if (args->direction == only_start)
		return (do_match_only(args, only_start));
	if (args->direction == only_end)
		return (do_match_only(args, only_end));
	if (args->direction == all_end)
		return (do_match_all_end(args));
	if (args->direction == start_all)
		return (do_match_start_all(args));
	if (args->direction == start_all_end)
		return (do_match_start_all_end(args));
	return (false);
}
