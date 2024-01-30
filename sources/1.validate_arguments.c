/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.validate_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:02:02 by matesant          #+#    #+#             */
/*   Updated: 2024/01/30 16:04:50 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int		ft_check_sort(t_stack *a);

void	ft_validate_alloc(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**numbers;

	i = 0;
	if (argc == 1)
	{
		ft_error("Missing arguments", stack_a, NULL);
	}
	if (argc > 2)
	{
		while (argv[++i])
			ft_end(stack_a, ft_atoi(argv[i]));
	}
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		i = 0;
		while (numbers[i])
			ft_end(stack_a, ft_atoi(numbers[i++]));
		ft_delete_matrice(numbers);
	}
	ft_check_sort(*stack_a);
}

t_stack	*ft_lstend2(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	ft_check_sort(t_stack *a)
{
	while (1)
	{
		if (a->next == NULL)
			return (1);
		if (a->next->x > a->x)
			a = a->next;
		else
			return (0);
	}
}
