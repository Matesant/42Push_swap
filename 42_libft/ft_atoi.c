/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:22:05 by matesant          #+#    #+#             */
/*   Updated: 2024/01/31 12:44:44 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	numbers;

	index = 0;
	numbers = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((str[index] != '\0' && str[index] == ' ') || (str[index] >= 9
			&& str[index] <= 13))
		index++;
	if (str[index] == '\0')
		return (0);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		numbers = numbers * 10 + (str[index] - '0');
		index++;
	}
	return (numbers * sign);
}
