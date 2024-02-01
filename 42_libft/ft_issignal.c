/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issignal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:12:33 by matesant          #+#    #+#             */
/*   Updated: 2024/02/01 12:15:06 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issignal(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
		return (1);
	}
	else
		return (0);
}

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
