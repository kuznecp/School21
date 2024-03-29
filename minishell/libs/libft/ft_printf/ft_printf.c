/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:25:00 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 21:25:01 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_args	args;

	if (s == NULL)
		return (-1);
	if (ft_strlen(s) == 0)
		return (0);
	args.len = 0;
	args.res = NULL;
	va_start(ap, s);
	ft_printf_get_conversions(s, &args, ap);
	va_end(ap);
	if (args.res == NULL)
		return (-1);
	(void)(write(1, args.res, args.len) + 1);
	free(args.res);
	return (args.len);
}
