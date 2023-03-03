/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:25:04 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/02/22 18:41:56 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(t_list **stack)
{
	int		size;
	t_list	*node;
	t_list	*prev;

	if (!stack)
		exit(1);
	node = (*stack);
	prev = node;
	size = ft_lstsize(*stack);
	while (size--)
	{
		if (!(node) || (int)(long)prev->content > (int)(long)node->content)
			return (FALSE);
		prev = node;
		node = node->next;
	}
	return (TRUE);
}

int	is_descending(t_list **stack)
{
	int		size;
	t_list	*node;
	t_list	*prev;

	if (!stack)
		exit(1);
	node = (*stack);
	prev = node;
	size = ft_lstsize(*stack);
	while (size--)
	{
		if (!(node) || (int)(long)prev->content < (int)(long)node->content)
			return (FALSE);
		prev = node;
		node = node->next;
	}
	return (TRUE);
}

int	get_max(t_list **stack_a, t_list **stack_b)
{
	int		max;
	t_list	*node;

	node = (*stack_a);
	max = (int)(long)node->content;
	while (node)
	{
		if ((int)(long)node->content > max)
			max = (int)(long)node->content;
		if (node == ft_lstlast(*stack_a))
			node = (*stack_b);
		else
			node = node->next;
	}
	return (max);
}

int	get_mid(t_list **stack)
{
	int		low;
	int		high;
	t_list	*node;

	node = *stack;
	low = (int)(long)node->content;
	high = (int)(long)node->content;
	while (node)
	{
		if ((int)(long)node->content < low)
			low = (int)(long)node->content;
		if ((int)(long)node->content > high)
			high = (int)(long)node->content;
		node = node->next;
	}
	return (low + ((high - low) / 2));
}

int	get_min(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*node;

	node = (*stack_a);
	min = get_max(stack_a, stack_b);
	while (node)
	{
		if ((int)(long)node->content < min)
			min = (int)(long)node->content;
		if (node == ft_lstlast(*stack_a))
			node = (*stack_b);
		else
			node = node->next;
	}
	return (min);
}
