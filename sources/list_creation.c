/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:13:17 by matesant          #+#    #+#             */
/*   Updated: 2024/01/30 10:41:46 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->x = value;
	node->next = NULL;
	return (node);
}

void	ft_end(t_stack **node, int value)
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

int	ft_listsize(t_stack *node)
{
	t_stack	*curr;
	int		len;

	len = 0;
	curr = node;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

void	ft_begin(t_stack **x, int value)
{
	t_stack	*node;

	node = ft_new_node(value);
	node->next = *x;
	node->x = value;
	*x = node;
}
