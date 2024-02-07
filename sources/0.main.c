/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:57 by matesant          #+#    #+#             */
/*   Updated: 2024/02/07 19:57:49 by matesant         ###   ########.fr       */
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
	else
		ft_go_big(a, b);
}

void	ft_same_digit(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->x > INT_MAX || temp->x < INT_MIN)
				ft_error("Error", a, NULL);
			if (temp->x == temp2->x)
				ft_error("Error", a, NULL);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	ft_swift(t_stack **a)
{
	int	small;
	int	size;

	small = 0;
	size = ft_listsize(*a) / 2;
	while (1)
	{
		small = ft_get_min(a);
		if (small == 0)
			return ;
		if (small < size)
			ft_ra(a);
		else
			ft_rra(a);
		ft_get_positions(a, NULL);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_ischaracter(++argv);
	ft_empty(argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_validate_alloc(argc, argv, &stack_a);
	ft_same_digit(&stack_a);
	ft_call_sort(&stack_a, &stack_b);
	ft_error(NULL, &stack_a, &stack_b);
	return (0);
}
