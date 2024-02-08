/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.validate_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:02:02 by matesant          #+#    #+#             */
/*   Updated: 2024/02/08 18:36:06 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int		ft_check_sort(t_stack *a);

void	ft_validate_alloc(char **argv, t_stack **stack_a)
{
	while (argv[ft_values()->i])
	{
		ft_values()->str = ft_strjoin(ft_values()->str, argv[ft_values()->i]);
		ft_values()->i++;
	}
	ft_values()->numbers = ft_split(ft_values()->str, ' ');
	ft_check_max(ft_values()->numbers, ft_values()->str);
	if (ft_values()->numbers == NULL)
		ft_error("Error\n", stack_a, NULL);
	while (ft_values()->numbers[ft_values()->ki])
		ft_end(stack_a, ft_atoi(ft_values()->numbers[ft_values()->ki++]));
	ft_delete_matrice(ft_values()->numbers);
	free(ft_values()->str);
	if (ft_check_sort(*stack_a) == 1)
		ft_error(NULL, stack_a, NULL);
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

void	ft_empty(char **str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		if ((!str) || (str[i][0] == '\0'))
			ft_easy_error("Error\n");
		k = 0;
		while (str[i][k])
		{
			ft_is_only_space(str[i]);
			ft_out_of_order_signals(str[i]);
			if (str[i][k] != ' ' && str[i][k] != '+' && str[i][k] != '-')
			{
				k++;
				continue ;
			}
			k++;
		}
		i++;
	}
}

void	ft_ischaracter(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && (!ft_isspace(str[i][j])))
				ft_easy_error("Error\n");
			j++;
		}
		i++;
	}
}
