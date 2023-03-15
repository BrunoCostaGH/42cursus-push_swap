/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_n_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:25:04 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 18:19:37 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**stack_init(int size)
{
	t_list	**stack;

	if (!size)
		return (0);
	stack = malloc(sizeof(t_list *) * (size + 1));
	if (!stack)
		exit (1);
	(*stack) = 0;
	return (stack);
}

char	**arr_init(int size)
{
	char	**stack;

	if (!size)
		return (0);
	stack = ft_calloc((size + 1), sizeof(char *));
	if (!stack)
		exit (1);
	(*stack) = 0;
	return (stack);
}

void	stack_free(t_list **stack)
{
	t_list	*node;

	while ((*stack))
	{
		node = (*stack)->next;
		free((*stack));
		(*stack) = node;
	}
	free(stack);
}

void	arr_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
