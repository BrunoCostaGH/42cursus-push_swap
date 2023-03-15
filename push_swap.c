/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:47:03 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 18:19:15 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	The goal is to sort in ascending order numbers into stack a. To do so you 
	have the following operations at your disposal:

		sa (swap a): Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one or no elements.

		sb (swap b): Swap the first 2 elements at the top of stack b.
		Do nothing if there is only one or no elements.

		ss : sa and sb at the same time.

		pa (push a): Take the first element at the top of b and put it at the top of a.
		Do nothing if b is empty.

		pb (push b): Take the first element at the top of a and put it at the top of b.
		Do nothing if a is empty.

		ra (rotate a): Shift up all elements of stack a by 1.
		The first element becomes the last one.

		rb (rotate b): Shift up all elements of stack b by 1.
		The first element becomes the last one.

		rr : ra and rb at the same time.

		rra (reverse rotate a): Shift down all elements of stack a by 1.
		The last element becomes the first one.

		rrb (reverse rotate b): Shift down all elements of stack b by 1.
		The last element becomes the first one.

		rrr : rra and rrb at the same time.
*/
/*
	Commands:
		1: clear && ARG=$(shuf -i 0-999 -n 10 | tr '\n' ' '); ./push_swap $ARG
		2: clear && make re && make clean
*/
/*
	Sort 'Lowest to Highest' stack a.
	Instructions must be separated by '\n'.
	The goal is to sort the stack with the lowest possible number of 
		operations. During the evaluation process, the number of instructions 
		found by your program will be compared against a limit: the maximum 
		number of operations tolerated. If your program either displays a 
		longer list or if the numbers aren’t sorted properly, your grade will be 0.
*/
static void	stack_sort(t_list **stack_a, char **arr, int size)
{
	int		min_pos;
	char	*operation;
	t_list	**stack_b;

	stack_b = stack_init(size);
	if (!stack_a || !stack_b)
		exit(1);
	operation = NULL;
	if (!is_ascending(stack_a))
		sort_algo(stack_a, stack_b, arr);
	if (ft_lstsize(*stack_b))
		return_to_stack(stack_a, stack_b);
	min_pos = get_min_pos(stack_a, stack_b);
	while (min_pos != 0)
	{
		if (!operation && min_pos > ft_lstsize(*stack_a) / 2)
			operation = "rra";
		else if (!operation)
			operation = "ra";
		run_operation(stack_a, stack_b, operation);
		min_pos = get_min_pos(stack_a, stack_b);
	}
	stack_free(stack_b);
}

/*
	Place integers into stack a, first argument at top.
*/
static void	stack_fill(t_list **stack_a, char **arr)
{
	int		i;
	t_list	*node;

	i = 0;
	while (arr[i])
	{
		node = ft_lstnew((void *)(long)ft_atoi(arr[i]));
		if ((*stack_a))
			ft_lstadd_back(stack_a, node);
		else
			(*stack_a) = node;
		i++;
	}
}

/*
	If no parameters are specified, the program must
		not display anything and give the prompt back.
*/
int	main(int argc, char **argv)
{
	int		size;
	char	**arr;
	t_list	**stack_a;

	if (argc > 1)
	{
		if (argc == 2)
			arr = ft_split(argv[1], ' ');
		else
			arr = argv + 1;
		size = arr_size(arr);
		stack_a = 0;
		stack_a = stack_init(size);
		if (!stack_a || !is_valid(arr))
			return (1);
		stack_fill(stack_a, arr);
		stack_sort(stack_a, arr, size);
		if (!is_ascending(stack_a))
			ft_printf("\n\e[1;41mStack is not sorted!\e[0m\n");
		stack_free(stack_a);
		if (argc == 2)
			arr_free(arr);
	}
	return (0);
}
