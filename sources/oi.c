/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:37:15 by matesant          #+#    #+#             */
/*   Updated: 2024/02/08 16:42:26 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_strip(char *str)
{
	size_t	len;
	size_t	start;
	size_t	end;

	if (str == NULL || *str == '\0')
		return ;
	len = ft_strlen(str);
	start = 0;
	end = len - 1;
	while (start < len && (str[start] == ' ' || str[start] == '\t'
			|| str[start] == '\n' || str[start] == '\v' || str[start] == '\f'
			|| str[start] == '\r'))
		start++;
	if (start == len)
	{
		free(str);
		str = NULL;
		return ;
	}
	while (str[end] && end > start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n' || str[end] == '\v' || str[end] == '\f'
			|| str[end] == '\r'))
		end--;
	ft_memmove(str, str + start, end - start + 1);
	str[end - start + 1] = '\0';
}
