/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.validate_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:02:02 by matesant          #+#    #+#             */
/*   Updated: 2024/02/02 12:23:09 by matesant         ###   ########.fr       */
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

	i = 0;
	ki = 0;
	str = NULL;
	if (argc == 1)
		ft_error("Missing arguments", stack_a, NULL);
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	numbers = ft_split(str, ' ');
	if (numbers == NULL)
		ft_error("Error\n", stack_a, NULL);
	while (numbers[ki])
		ft_end(stack_a, ft_atoi(numbers[ki++]));
	ft_delete_matrice(numbers);
	free(str);
	if (ft_check_sort(*stack_a) == 1)
		ft_error(NULL, stack_a, NULL);
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

void	ft_empty(char **str)
{
	int	i;
	int	k;

	i = 0;
	if ((!str))
		ft_easy_error("Error\n");
	while (str[i])
	{
		k = 0;
		while (str[i][k])
		{
			if (str[i][k] != ' ')
			{
				k++;
				continue ;
			}
			if (str[i][k] == ' ' && str[i][k + 1] == '\0')
				ft_easy_error("Error\n");
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
