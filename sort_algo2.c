/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:56:54 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 18:19:07 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotation(t_list *stack_0, t_list *stack_1, char *dir)
{
	int		i;
	t_list	*node;

	i = 0;
	if ((stack_0))
	{
		node = (stack_1);
		while (node)
		{
			if (ft_strncmp(dir, "ab", 2) == 0)
			{
				if ((int)(long)(stack_0)->content > (int)(long)node->content)
					break ;
			}
			else
			{
				if ((int)(long)(stack_0)->content < (int)(long)node->content)
					break ;
			}
			node = node->next;
			i++;
		}
	}
	return (i);
}

void	check_fragments_2(t_list *stack, int cur_value, int step, int *temp)
{
	int		i;

	i = 0;
	while (stack)
	{
		temp[0] = cur_value;
		temp[1] = i++;
		while (temp[0] != cur_value + step)
		{
			if ((int)(long)stack->content == temp[0])
			{
				if (!temp[2])
					temp[2] = temp[1];
				else
					temp[3] = temp[1];
				break ;
			}
			temp[0]++;
		}
		stack = stack->next;
	}
}

int	check_fragments(t_list *stack, int cur_value, int step)
{
	int		size;
	int		temp_first;
	int		temp_last;
	int		*temp;

	size = ft_lstsize(stack);
	temp = ft_calloc(4, sizeof(int));
	check_fragments_2(stack, cur_value, step, temp);
	temp_first = temp[2];
	temp_last = temp[3];
	if (!temp_first && !temp_last)
	{
		free(temp);
		return (-1);
	}
	if (temp_first < size - temp_last)
	{
		free(temp);
		return (temp_first);
	}
	else
	{
		free(temp);
		return (temp_last);
	}
}
