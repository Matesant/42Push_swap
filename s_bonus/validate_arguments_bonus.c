/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:02:02 by matesant          #+#    #+#             */
/*   Updated: 2024/02/27 19:48:24 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_sort(t_stack *a);

void	ft_validate_alloc(char **argv, t_stack **stack_a)
{
	int		i;
	char	**numbers;
	char	*str;
	int		ki;

	i = 0;
	ki = 0;
	str = ft_strdup("");
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	numbers = ft_split(str, ' ');
	ft_check_max(numbers, str);
	if (numbers == NULL)
		ft_error("Error", stack_a, NULL);
	while (numbers[ki])
		ft_end(stack_a, ft_atoi(numbers[ki++]));
	ft_delete_matrice(numbers);
	free(str);
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

void	ft_empty(char **str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\0' || !str)
			exit(0);
		k = 0;
		while (str[i][k])
		{
			if ((str[i][k] == '-' || str[i][k] == '+') && !ft_isdigit(str[i][k
					+ 1]))
				ft_error("Error", NULL, NULL);
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
				ft_easy_error("Error");
			j++;
		}
		i++;
	}
}
