/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:04:39 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 18:19:26 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_operation_2(t_list **stack_0, t_list **stack_1, char *operation)
{
	int	status;

	status = 0;
	if (ft_strncmp("ra", operation, 3) == 0)
		status = shift(stack_0);
	else if (ft_strncmp("rb", operation, 3) == 0)
		status = shift(stack_1);
	else if (ft_strncmp("rr", operation, 3) == 0)
	{
		status = shift(stack_0);
		status = shift(stack_1);
	}
	else if (ft_strncmp("rra", operation, 3) == 0)
		status = shift_r(stack_0);
	else if (ft_strncmp("rrb", operation, 3) == 0)
		status = shift_r(stack_1);
	else if (ft_strncmp("rrr", operation, 3) == 0)
	{
		status = shift_r(stack_0);
		status = shift_r(stack_1);
	}
	return (status);
}

void	run_operation(t_list **stack_0, t_list **stack_1, char *operation)
{
	int	status;

	status = 0;
	if (ft_strncmp("sa", operation, 3) == 0)
		status = swap(stack_0);
	else if (ft_strncmp("sb", operation, 3) == 0)
		status = swap(stack_1);
	else if (ft_strncmp("ss", operation, 3) == 0)
	{
		status = swap(stack_0);
		status = swap(stack_1);
	}
	else if (ft_strncmp("pa", operation, 3) == 0)
		status = push(stack_1, stack_0);
	else if (ft_strncmp("pb", operation, 3) == 0)
		status = push(stack_0, stack_1);
	else
		status = run_operation_2(stack_0, stack_1, operation);
	if (DEV_MODE && status)
	{
		ft_printf("\nExecuting operation...\n\n");
		run_dev_ops(stack_0, stack_1);
	}
	if (status)
		ft_printf("%s\n", operation);
}

void	run_dev_ops(t_list **stack_0, t_list **stack_1)
{
	t_list	*n_0;
	t_list	*n_1;

	n_0 = (*stack_0);
	n_1 = (*stack_1);
	while ((n_0) || (n_1))
	{
		if (n_0 && n_1)
			ft_printf("\t%d\t%d\n", (long)(n_0)->content, (long)(n_1)->content);
		else if (n_0)
			ft_printf("\t%d\t \n", (int)(long)(n_0)->content);
		else if (n_1)
			ft_printf("\t \t%d\n", (int)(long)(n_1)->content);
		if (n_0 && (n_0)->next)
			(n_0) = (n_0)->next;
		else
			(n_0) = 0;
		if (n_1 && (n_1)->next)
			(n_1) = (n_1)->next;
		else
			(n_1) = 0;
	}
	ft_printf("\t-\t-\n");
	ft_printf("\ta\tb\n");
	ft_printf("\nExecuted: ");
}
