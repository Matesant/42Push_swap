/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:52:59 by matesant          #+#    #+#             */
/*   Updated: 2024/02/06 17:17:54 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	list_to_tab(t_stack *a, int *tab)
{
	int	i;

	i = 0;
	while (a)
	{
		tab[i] = a->x;
		a = a->next;
		i++;
	}
}

void	ft_bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_create_index(t_stack **a, int *tab)
{
	int		i;
	t_stack	*temp;
	int		j;

	i = 0;
	temp = *a;
	while (temp)
	{
		j = 0;
		while (tab[j] != temp->x && tab[j] != '\0')
			j++;
		if (tab[j] == temp->x)
			temp->index = j;
		temp = temp->next;
	}
}
