/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:02:20 by matesant          #+#    #+#             */
/*   Updated: 2024/02/06 11:48:51 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

typedef struct s_atol
{
	int		i;
	long	sign;
	long	numbers;
}			t_atol;

void		ft_dealocate(t_stack **node);

void	ft_easy_error(char *str)
{
	ft_putstr_fd(str, 2);
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
		exit(0);
	}
	else
	{
		ft_printf("%s\n", str);
		if (a)
			ft_dealocate(a);
		if (b)
			ft_dealocate(b);
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

long	ft_atol(const char *str)
{
	t_atol	at;

	at.i = 0;
	at.numbers = 0;
	at.sign = 1;
	while ((str[at.i] && str[at.i] == ' ') || (str[at.i] >= 9
			&& str[at.i] <= 13))
		at.i++;
	if (str[at.i] == '\0')
		return (0);
	if (str[at.i] == '-' || str[at.i] == '+')
	{
		if (str[at.i] == '-')
			at.sign *= -1;
		at.i++;
	}
	while (str[at.i] >= '0' && str[at.i] <= '9')
	{
		at.numbers = at.numbers * 10 + (str[at.i] - '0');
		at.i++;
	}
	if (at.numbers > 2147483647 || at.numbers < -2147483648)
		ft_error("Error", NULL, NULL);
	return (at.numbers * at.sign);
}
