/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:38:50 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 18:19:18 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		max[2];
	t_list	*node;

	i = 0;
	node = (*stack_a);
	max[0] = (int)(long)node->content;
	while (node)
	{
		if ((int)(long)node->content > max[0])
		{
			max[0] = (int)(long)node->content;
			max[1] = i;
		}
		if (node == ft_lstlast(*stack_a))
			node = (*stack_b);
		else
			node = node->next;
		i++;
	}
	return (max[1]);
}

int	get_min_pos(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		min[2];
	t_list	*node;

	i = 0;
	node = (*stack_a);
	min[0] = get_max(stack_a, stack_b);
	min[1] = 0;
	while (node)
	{
		if ((int)(long)node->content < min[0])
		{
			min[0] = (int)(long)node->content;
			min[1] = i;
		}
		if (node == ft_lstlast(*stack_a))
			node = (*stack_b);
		else
			node = node->next;
		i++;
	}
	return (min[1]);
}
