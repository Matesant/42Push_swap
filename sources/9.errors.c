/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:02:20 by matesant          #+#    #+#             */
/*   Updated: 2024/02/01 12:20:31 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_dealocate(t_stack **node);

void	ft_easy_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_error(char *str, t_stack **a, t_stack **b)
{
	if (str == NULL)
	{
		ft_dealocate(a);
		if (b)
			ft_dealocate(b);
		exit(0);
	}
	else
	{
		ft_printf("%s\n", str);
		ft_dealocate(a);
		if (b)
			ft_dealocate(b);
		exit(0);
	}
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
	free(curr);
	*node = NULL;
}

void	ft_delnode(t_stack **node)
{
	t_stack	*temp;

	temp = *node;
	*node = (*node)->next;
	free(temp);
}
