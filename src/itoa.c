/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:14:18 by riolivei          #+#    #+#             */
/*   Updated: 2022/12/04 15:52:48 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		array[3];

	array[0] = 0;
	if (n < 0)
		array[0]++;
	array[2] = is_negative(n);
	if (array[2] == 147483648)
		array[0] = 2;
	array[1] = num_digits(array[2]);
	str = (char *)malloc(sizeof(char) * (array[1] + 1));
	if (!str)
		return (0);
	str[array[1]] = '\0';
	if (n == 0)
		str[--array[1]] = '0';
	while (array[2] != 0)
	{
		str[--array[1]] = (array[2] % 10) + 48;
		array[2] /= 10;
	}
	return (str);
}

int	is_negative(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		return (147483648);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		return (n * (-1));
	}
	return (n);
}

int	num_digits(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}
