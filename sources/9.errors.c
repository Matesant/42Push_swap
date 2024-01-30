/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:02:20 by matesant          #+#    #+#             */
/*   Updated: 2024/01/30 15:45:25 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_dealocate(t_stack **node);

void	ft_error(char *str, t_stack **a, t_stack **b)
{
	ft_printf("%s\n", str);
	ft_dealocate(a);
	if (b)
		ft_dealocate(b);
	exit(0);
}

void	ft_dealocate(t_stack **node)
{
	t_stack	*temp;
	t_stack	*curr;

	curr = *node;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free (curr);
	*node = NULL;
}

void	ft_delnode(t_stack **node)
{
	t_stack	*temp;

	temp = *node;
	*node = (*node)->next;
	free(temp);
}