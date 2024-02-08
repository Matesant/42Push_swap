/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:16:16 by matesant          #+#    #+#             */
/*   Updated: 2024/02/08 18:37:10 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../42_libft/Printf/ft_printf.h"
# include "../42_libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				x;
	struct s_stack	*next;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}					t_stack;

typedef struct s_values
{
	int				i;
	char			**numbers;
	char			*str;
	int				ki;
}					t_values;

// structs
void				ft_init_struct(void);
t_values			*ft_values(void);

// error handling
void				ft_error(char *str, t_stack **a, t_stack **b);
void				ft_dealocate(t_stack **node);
void				ft_empty(char **str);
void				ft_easy_error(char *str);
void				ft_ischaracter(char **str);
void				ft_check_max(char **numbers, char *str);
void				ft_same_digit(t_stack **a);
void				ft_is_only_space(char *str);
void				ft_out_of_order_signals(char *str);

// nodes creation
t_stack				*ft_new_node(int value);
void				ft_end(t_stack **node, int value);
void				ft_validate_alloc(char **argv, t_stack **stack_a);
int					ft_listsize(t_stack *node);
void				ft_begin(t_stack **x, int value);
t_stack				*ft_lstend(t_stack *lst);
t_stack				*ft_lstend2(t_stack *lst);
void				ft_strip(char *str);

// sorting
void				ft_sort_three(t_stack **a);
void				ft_sort_two(t_stack **a);
void				ft_below_fifty(t_stack **a, t_stack **b);
int					ft_check_sort(t_stack *a);
void				ft_go_big(t_stack **a, t_stack **b);
int					ft_get_min(t_stack **a);
void				ft_swift(t_stack **a);

// index creation
void				ft_create_index(t_stack *a, int *tab);
void				ft_bubble_sort(int *tab, int size);
void				list_to_tab(t_stack *a, int *tab);

// weights
void				ft_get_positions(t_stack **a, t_stack **b);
int					ft_get_target(t_stack *a, int b_index);
void				ft_get_costs(t_stack *a, t_stack *b);
void				ft_update_target_pos(t_stack *a, t_stack *b);
void				ft_real_math(t_stack **a, t_stack **b);

// instructions
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				ft_sb(t_stack **b);
void				ft_sa(t_stack **a);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_rb(t_stack **b);
void				ft_ra(t_stack **a);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rrb(t_stack **b);
void				ft_rra(t_stack **a);
void				ft_rrr(t_stack **a, t_stack **b);

void				ft_print_stack(t_stack *b);
#endif