/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:53:51 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/02/06 16:25:04 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swap the first 2 elements at the top of a stack.
	Do nothing if there is only one or no elements.
*/
int	swap(t_list **stack)
{
	void	*content;

	if ((*stack) && (*stack)->next)
	{
		content = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = content;
		return (TRUE);
	}
	return (FALSE);
}

/*
	Take the first element at the top of a stack and put it at the top of the other.
	Do nothing if first stack is empty.
*/
int	push(t_list **stack_0, t_list **stack_1)
{
	t_list	*n_a;
	t_list	*n_b;

	if ((*stack_0))
	{
		n_a = (*stack_0);
		n_b = ft_lstnew((*stack_0)->content);
		if ((*stack_1))
			ft_lstadd_front(stack_1, n_b);
		else
			(*stack_1) = n_b;
		(*stack_0) = (*stack_0)->next;
		free(n_a);
		return (TRUE);
	}
	return (FALSE);
}

/*
	Shift up all elements of a stack by 1.
	The first element becomes the last one.
*/
int	shift(t_list **stack)
{
	t_list	*node;

	if ((*stack))
	{
		node = (*stack);
		(*stack) = (*stack)->next;
		ft_lstadd_back(stack, node);
		node->next = 0;
		return (TRUE);
	}
	return (FALSE);
}

/*
	Shift down all elements of a stack by 1.
	The last element becomes the first one.
*/
int	shift_r(t_list **stack)
{
	t_list	*first;
	t_list	*blast;
	t_list	*last;

	if ((*stack))
	{
		first = (*stack);
		last = (*stack);
		while (last->next)
		{
			blast = last;
			last = last->next;
		}
		(*stack) = last;
		(*stack)->next = first;
		blast->next = 0;
		return (TRUE);
	}
	return (FALSE);
}
