/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.list_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:23:23 by matesant          #+#    #+#             */
/*   Updated: 2024/02/28 14:24:21 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_lstend2(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_is_only_space(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			flag = 1;
		if (str[i + 1] == '\0' && flag == 0)
			ft_error("Error", NULL, NULL);
		if (str[i + 1] == '\0' && flag == 1)
			return ;
		i++;
	}
}

void	ft_out_of_order_signals(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] < '0' && str[i + 1] > '9'))
			ft_error("Error", NULL, NULL);
		if (str[i] == '+' && (str[i + 1] < '0' && str[i + 1] > '9'))
			ft_error("Error", NULL, NULL);
		if (str[i] == '-' && str[i - 1] != ' ' && str[i - 1] != '\0')
			ft_error("Error", NULL, NULL);
		if (str[i] == '+' && str[i - 1] != ' ' && str[i - 1] != '\0')
			ft_error("Error", NULL, NULL);
		i++;
	}
}
