/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoghurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:24:39 by hyoghurt          #+#    #+#             */
/*   Updated: 2021/06/21 11:40:37 by hyoghurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi_long(const char *nptr)
{
	long	result;
	int		i;
	long	d;

	result = 0;
	d = 1;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 8) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			d = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = (nptr[i] - '0') + result * 10;
		i++;
	}
	return (result * d);
}
