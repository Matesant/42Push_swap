/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:31 by matesant          #+#    #+#             */
/*   Updated: 2024/02/28 11:45:51 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_moves(t_stack **a, t_stack **b, char *line);
void	read_moves(t_stack **a, t_stack **b);
int		ft_is_sorted(t_stack *a);
void	ft_byebye(char *str, t_stack **a, t_stack **b, char *line);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(0);
	ft_ischaracter(++argv);
	ft_empty(argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_validate_alloc(argv, &stack_a);
	ft_same_digit(&stack_a);
	read_moves(&stack_a, &stack_b);
	if (ft_is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_error(NULL, &stack_a, &stack_b);
	return (0);
}

int	ft_is_sorted(t_stack *a)
{
	while (1)
	{
		if (a->next == NULL)
			return (1);
		if (a->x < a->next->x)
			a = a->next;
		else
			return (0);
	}
}

void	read_moves(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_moves(a, b, line);
		free(line);
	}
	free(line);
	get_next_line(-1);
}

void	ft_moves(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		ft_sa(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		ft_sb(b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ft_ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		ft_pa(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		ft_pb(a, b);
	else if (!ft_strncmp(line, "ra\n", 3))
		ft_ra(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		ft_rb(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		ft_rr(a, b);
	else if (!ft_strncmp(line, "rra\n", 4))
		ft_rra(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		ft_rrb(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		ft_rrr(a, b);
	else
		ft_byebye("Error", a, b, line);
}

void	ft_byebye(char *str, t_stack **a, t_stack **b, char *line)
{
	free(line);
	ft_error(str, a, b);
}
