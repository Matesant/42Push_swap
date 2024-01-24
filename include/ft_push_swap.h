/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:16:16 by matesant          #+#    #+#             */
/*   Updated: 2024/01/24 16:42:35 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../42_libft/libft.h"
# include "../Printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				x;
	struct s_stack	*next;
}					t_stack;

// error handling
void				ft_error(char *str);
void				ft_dealocate(t_stack **node);

// nodes creation
t_stack				*ft_new_node(int value);
void				ft_after(t_stack **node, int value);
void				ft_validate_alloc(int argc, char **argv, t_stack **stack_a);
#endif