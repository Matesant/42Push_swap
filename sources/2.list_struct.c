/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.list_&_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:23:23 by matesant          #+#    #+#             */
/*   Updated: 2024/02/08 17:28:49 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

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
