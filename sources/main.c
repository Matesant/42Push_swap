/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:26:21 by matesant          #+#    #+#             */
/*   Updated: 2024/01/16 16:25:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}					t_node;

int	main(void)
{
	t_node	opa;
	t_node	*currentes;

	opa.x = 42;
	opa.next = malloc(sizeof(t_node));
	opa.next->x = 84;
	opa.next->next = malloc(sizeof(t_node));
	opa.next->next->x = 37;
	opa.next->next->next = malloc(sizeof(t_node));
	opa.next->next->next->x = 21;
	opa.next->next->next->next = malloc(sizeof(t_node));
	opa.next->next->next->next->x = 12;
	opa.next->next->next->next->next = NULL;
	currentes = &opa;
	while (currentes)
	{
		ft_printf("%d\n", currentes->x);
		currentes = currentes->next;
	}
	free(opa.next->next->next->next);
	free(opa.next->next->next);
	free(opa.next->next);
	free(opa.next);
	return (0);
}
