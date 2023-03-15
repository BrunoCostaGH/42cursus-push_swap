/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:47:41 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 18:19:13 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <unistd.h>

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef DEV_MODE
#  define DEV_MODE FALSE
# endif

int			swap(t_list **stack);
int			arr_size(char **arr);
int			is_valid(char **arr);
int			shift(t_list **stack);
int			shift_r(t_list **stack);
int			get_mid(t_list **stack);
int			is_ascending(t_list **stack);
int			is_descending(t_list **stack);
int			push(t_list **stack_0, t_list **stack_1);
int			get_max(t_list **stack_a, t_list **stack_b);
int			get_min(t_list **stack_a, t_list **stack_b);
int			get_min_pos(t_list **stack_a, t_list **stack_b);
int			get_max_pos(t_list **stack_a, t_list **stack_b);
int			check_fragments(t_list *stack, int cur_value, int step);
int			get_rotation(t_list *stack_0, t_list *stack_1, char *dir);

long int	ft_atol(const char *nptr);

void		arr_free(char **arr);
void		stack_free(t_list **stack);
void		run_dev_ops(t_list **stack_a, t_list **stack_b);
void		return_to_stack(t_list **stack_a, t_list **stack_b);
void		stack_split(t_list **stack_a, t_list **stack_b, int size);
void		run_operation(t_list **stack_0, t_list **stack_1, char *operation);
void		sort_algo(t_list **stack_a, t_list **stack_b, char **arr);

char		**arr_init(int size);

t_list		**stack_init(int size);

#endif
