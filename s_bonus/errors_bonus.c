/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:02:20 by matesant          #+#    #+#             */
/*   Updated: 2024/02/20 12:17:42 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_dealocate(t_stack **node);

void	ft_easy_error(char *str)
{
	ft_putendl_fd(str, 2);
	get_next_line(-1);
	exit(1);
}

void	ft_error(char *str, t_stack **a, t_stack **b)
{
	if (str == NULL)
	{
		if (a)
			ft_dealocate(a);
		if (b)
			ft_dealocate(b);
		get_next_line(-1);
		exit(0);
	}
	else
	{
		ft_putendl_fd(str, 2);
		if (a)
			ft_dealocate(a);
		if (b)
			ft_dealocate(b);
		get_next_line(-1);
		exit(0);
	}
}

void	ft_dealocate(t_stack **node)
{
	t_stack	*temp;
	t_stack	*curr;

	curr = *node;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(curr);
	*node = NULL;
}

void	ft_delnode(t_stack **node)
{
	t_stack	*temp;

	temp = *node;
	*node = (*node)->next;
	free(temp);
}

void	ft_check_max(char **numbers, char *str)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (ft_atol(numbers[i]) > INT_MAX || ft_atol(numbers[i]) < INT_MIN)
		{
			ft_delete_matrice(numbers);
			free(str);
			ft_error("Error", NULL, NULL);
		}
		i++;
	}
}
