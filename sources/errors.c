/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:02:20 by matesant          #+#    #+#             */
/*   Updated: 2024/01/24 16:58:25 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	ft_dealocate(t_stack **node)
{
	t_stack	*temp;
	t_stack	*curr;

	curr = *node;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*node = NULL;
}
