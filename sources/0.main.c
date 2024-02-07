/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:57 by matesant          #+#    #+#             */
/*   Updated: 2024/02/07 16:02:32 by matesant         ###   ########.fr       */
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
	else if (len < 5)
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

void	ft_print_stack(t_stack *b)
{
	while (b)
	{
		printf("\t-------------------------------\n");
		printf("\t\tNumber: %d\n", b->x);
		printf("\t\tIndex: %d\n", b->index);
		printf("\t\ttarget pos: %d\n", b->target_pos);
		printf("\t\tpos: %d\n", b->position);
		printf("\t\tcost_a: %d\n", b->cost_a);
		printf("\t\tcost_b: %d\n", b->cost_b);
		b = b->next;
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
	printf("\t\tstack_a:\n");
	ft_print_stack(stack_a);
	printf("\v\v\t\tstack_b:\n");
	ft_print_stack(stack_b);
	printf("min index position: %d\n", ft_get_min(&stack_a));
	return (0);
}
