/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:23:23 by matesant          #+#    #+#             */
/*   Updated: 2024/02/15 18:52:58 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_values	*ft_values(void)
{
	static t_values	values;

	return (&values);
}

void	ft_init_struct(void)
{
	t_values	*values;

	values = ft_values();
	values->i = 0;
	values->ki = 0;
	values->str = NULL;
	values->numbers = NULL;
}

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

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] >= 9 || str[i] <= 13)
			return ;
		i++;
	}
	ft_error("Error", NULL, NULL);
}

void	ft_out_of_order_signals(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
			ft_error("Error", NULL, NULL);
		if (str[i] == '+' && (str[i + 1] < '0' || str[i + 1] > '9'))
			ft_error("Error", NULL, NULL);
		i++;
	}
}
