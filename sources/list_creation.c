/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:13:17 by matesant          #+#    #+#             */
/*   Updated: 2024/01/24 15:50:16 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(node));
	node->x = value;
	node->next = NULL;
	return (node);
}

void	ft_after(t_stack **node, int value)
{
	t_stack	*curr;

	if (*node == NULL)
	{
		*node = ft_new_node(value);
		return ;
	}
	curr = *node;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = ft_new_node(value);
}
