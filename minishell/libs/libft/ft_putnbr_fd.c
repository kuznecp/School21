/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuriko <myuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:27:41 by myuriko           #+#    #+#             */
/*   Updated: 2022/08/23 21:27:41 by myuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
n is the number to write, from the int range.
fd is the file descriptor number to write.

Description:
The function writes the given int n to the file with the descriptor fd.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int					i;
	unsigned long long	ulln;
	unsigned long long	dev;
	char				res[12];

	i = 0;
	dev = 10;
	ulln = n;
	if (n < 0)
	{
		res[i++] = '-';
		ulln *= -1;
	}
	while (ulln % dev != ulln)
		dev *= 10;
	while (dev != 1)
	{
		dev /= 10;
		res[i++] = ulln / dev + 48;
		ulln = ulln % dev;
	}
	(void)(write(fd, &res, i) + 1);
}
