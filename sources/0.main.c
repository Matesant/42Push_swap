/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:57 by matesant          #+#    #+#             */
/*   Updated: 2024/01/31 12:59:39 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_call_sort(t_stack **a, t_stack **b)
{
	int	len;

	*b = NULL;
	len = ft_listsize(*a);
	if (len == 2)
		ft_sort_two(a);
	else if (len == 3)
		return ;
		//ft_sort_three(a);
	else
		return ;
		//ft_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;

	stack_a = NULL;
	stack_b = NULL;
	ft_validate_alloc(argc, argv, &stack_a);
	ft_call_sort(&stack_a, &stack_b);
	temp = stack_a;
	while (temp)
	{
		ft_printf("%d\n", temp->x);
		temp = temp->next;
	}
	ft_error("ALL right", &stack_a, &stack_b);
	return (0);
}
