/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:48:14 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/02/23 17:33:26 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_to_stack(t_list **stack_a, t_list **stack_b)
{
	int		opt_push;
	char	*operation;

	opt_push = get_rotation((*stack_b), (*stack_a), "ba");
	if ((opt_push) > (ft_lstsize(*stack_a) / 2))
	{
		opt_push = ft_lstsize((*stack_a)) - opt_push;
		operation = "rra";
	}
	else
		operation = "ra";
	if (opt_push > 0 && ft_lstsize(*stack_a) > 1 \
	&& opt_push != (ft_lstsize(*stack_a)))
	{
		while (opt_push--)
			run_operation(stack_a, stack_b, operation);
	}
	while (!is_ascending(stack_a) && opt_push == 0 && \
	(int)(long)(*stack_b)->content < \
	(int)(long)ft_lstlast(*stack_a)->content)
		run_operation(stack_a, stack_b, "rra");
	run_operation(stack_a, stack_b, "pa");
	while (ft_lstsize(*stack_b))
		return_to_stack(stack_a, stack_b);
}

void	sort_algo_3(t_list **stack_a, t_list **stack_b)
{
	int		opt_push;
	char	*operation;

	opt_push = get_rotation((*stack_a), (*stack_b), "ab");
	if ((opt_push) > (ft_lstsize(*stack_b) / 2))
	{
		opt_push = ft_lstsize((*stack_b)) - opt_push;
		operation = "rrb";
	}
	else
		operation = "rb";
	if (opt_push > 0 && ft_lstsize(*stack_b) > 1 \
	&& opt_push != (ft_lstsize(*stack_b)))
	{
		while (opt_push--)
			run_operation(stack_a, stack_b, operation);
	}
	run_operation(stack_a, stack_b, "pb");
}

void	sort_algo_2(t_list **stack_a, t_list **stack_b)
{
	int		step;
	int		cur_value;
	int		opt_moves;
	char	*operation;

	cur_value = get_min(stack_a, stack_b);
	step = ((0 + (get_max(stack_a, stack_b) - get_min(stack_a, stack_b))) / 5);
	opt_moves = check_fragments((*stack_a), cur_value, step);
	while (opt_moves == -1 && cur_value < get_max(stack_a, stack_b))
	{
		cur_value += step;
		opt_moves = check_fragments((*stack_a), cur_value, step);
	}
	if (opt_moves > ft_lstsize((*stack_a)) / 2)
	{
		opt_moves = ft_lstsize((*stack_a)) - opt_moves;
		operation = "rra";
	}
	else
		operation = "ra";
	while (opt_moves--)
		run_operation(stack_a, stack_b, operation);
	sort_algo_3(stack_a, stack_b);
}

void	sort_algo(t_list **stack_a, t_list **stack_b, char **arr)
{
	while ((*stack_a) && (int)(long)(*stack_a)->content > \
	(int)(long)ft_lstlast(*stack_a)->content)
		run_operation(stack_a, stack_b, "ra");
	if ((*stack_a) && (*stack_a)->next)
	{
		if ((int)(long)(*stack_a)->content > \
		(int)(long)(*stack_a)->next->content)
			run_operation(stack_a, stack_b, "sa");
	}
	while ((*stack_b) && (int)(long)(*stack_b)->content < \
	(int)(long)ft_lstlast(*stack_b)->content)
		run_operation(stack_a, stack_b, "rb");
	if (!is_ascending(stack_a))
		run_operation(stack_a, stack_b, "pb");
	if ((*stack_a) && (*stack_a)->next)
	{
		if ((int)(long)(*stack_a)->content > \
		(int)(long)(*stack_a)->next->content)
			run_operation(stack_a, stack_b, "sa");
	}
	while (!is_ascending(stack_a) && ft_lstsize(*stack_a) > 5)
		sort_algo_2(stack_a, stack_b);
	if (!is_ascending(stack_a) && ft_lstsize(*stack_a) > 0)
		sort_algo(stack_a, stack_b, arr);
}
