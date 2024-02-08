/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:57 by matesant          #+#    #+#             */
/*   Updated: 2024/02/08 19:06:27 by matesant         ###   ########.fr       */
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
		ft_sort_three(a);
	else if (len < 50)
		ft_below_fifty(a, b);
	else if (len < 2001)
		ft_go_big(a, b);
	else
		ft_below_fifty(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		ft_error("Missing arguments", NULL, NULL);
	ft_init_struct();
	ft_ischaracter(++argv);
	ft_empty(argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_validate_alloc(argv, &stack_a);
	ft_same_digit(&stack_a);
	ft_call_sort(&stack_a, &stack_b);
	ft_error(NULL, &stack_a, &stack_b);
	return (0);
}
