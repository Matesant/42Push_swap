/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.validate_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:02:02 by matesant          #+#    #+#             */
/*   Updated: 2024/01/31 14:31:44 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int		ft_check_sort(t_stack *a);

void	ft_validate_alloc(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**numbers;
	char	*str;
	int		ki;

	i = 1;
	ki = 0;
	str = NULL;
	if (argc == 1)
		ft_error("Missing arguments", stack_a, NULL);
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	ft_printf("str = %s\n", str);
	numbers = ft_split(str, ' ');
	while (numbers[ki])
		ft_end(stack_a, ft_atoi(numbers[ki++]));
	ft_delete_matrice(numbers);
	free(str);
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
