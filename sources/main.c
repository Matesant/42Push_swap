/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:26:21 by matesant          #+#    #+#             */
/*   Updated: 2024/01/23 15:41:20 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}					t_node;

t_node	*ft_novo(int valore)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->x = valore;
	node->next = NULL;
	return (node);
}

void	begin(t_node **opa, int value)
{
	t_node	*node;

	node = ft_novo(value);
	node->next = *opa;
	*opa = node;
}

void	after(t_node **opa, int value)
{
	t_node	*curr;
	t_node	*temp;

	curr = *opa;
	while (curr->x < value && curr->next->x < value)
	{
		curr = curr->next;
	}
	temp = curr->next;
	curr->next = ft_novo(value);
	curr->next->next = temp;
}

void	sort(t_node **opa, int value)
{
	t_node	*curr;

	curr = *opa;
	if (curr->x >= value)
	{
		begin(opa, value);
		return ;
	}
	else
	{
		while (curr->next)
		{
			if (curr->x >= value)
			{
				after(opa, value);
				return ;
			}
			curr = curr->next;
		}
		if (curr->x < value)
			(curr)->next = ft_novo(value);
	}
}

void	ft_dealocatt(t_node **opa)
{
	t_node	*curr;
	t_node	*temp;

	curr = *opa;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

int	main(void)
{
	t_node	*opa;
	t_node	*curre;

	opa = ft_novo(14);
	sort(&opa, 10);
	sort(&opa, 9);
	sort(&opa, 15);
	sort(&opa, 12);
	sort(&opa, 13);
	sort(&opa, 11);
	curre = opa;
	while (curre != NULL)
	{
		printf("%d\n", curre->x);
		curre = curre->next;
	}
	ft_dealocatt(&opa);
	return (0);
}
