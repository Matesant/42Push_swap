/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:57 by matesant          #+#    #+#             */
/*   Updated: 2024/01/24 16:58:08 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;

	ft_bzero(&stack_a, sizeof(stack_a));
	stack_b = NULL;
	ft_validate_alloc(argc, argv, &stack_a);
	temp = stack_a;
	while (temp)
	{
		ft_printf("%d\n", temp->x);
		temp = temp->next;
	}
	ft_dealocate(&stack_a);
	return (0);
}
