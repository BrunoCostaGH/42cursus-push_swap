/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:47:07 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/01 17:09:05 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Exit with error.
*/
static void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/*
	Check if there are duplicates.
*/
static void	check_duplicate(char **arr)
{
	int		i;
	int		k;
	char	**checked;

	i = 0;
	if (DEV_MODE)
		ft_printf("\nChecking for duplicates...\n");
	checked = arr_init(arr_size(arr));
	while (arr[i])
	{
		k = 0;
		while (checked[k])
		{
			if (DEV_MODE)
				ft_printf("\tChecking %s against %s.\n", arr[i], checked[k]);
			if (ft_strncmp(checked[k], arr[i], ft_strlen(arr[i])) == 0)
			{
				if (ft_strncmp(arr[i], checked[k], ft_strlen(checked[k])) == 0)
					exit_error();
			}
			k++;
		}
		checked[k] = arr[i++];
	}
	free(checked);
}

/*
	Check if number higher than integer max value.
*/
static void	check_max_int(char *arr)
{
	int long	number;

	number = ft_atol(arr);
	if (DEV_MODE)
		ft_printf("\tChecking if %s is higher than INT_MAX.\n", arr);
	if (number > INT_MAX)
		exit_error();
}

/*
	Check if number lower than integer min value.
*/
static void	check_min_int(char *arr)
{
	int long	number;

	number = ft_atol(arr);
	if (DEV_MODE)
		ft_printf("\tChecking if %s is lower than INT_MIN.\n", arr);
	if (number < INT_MIN)
		exit_error();
}

/*
	Check if argv[1] is integers.
	In case of error, it must display "Error" followed by a ’\n’ on the 
		standard error.
		Errors include for example: some arguments aren’t integers, 
		some arguments are bigger than an integer and/or there are duplicates.
*/
int	is_valid(char **arr)
{
	int		i;
	int		k;

	i = 0;
	if (DEV_MODE)
		ft_printf("\n\e[1;43mChecking for errors...\e[0m\n");
	while (arr[i])
	{
		k = -1;
		if (DEV_MODE)
			ft_printf("\nChecking if %s is an integer.\n", arr[i]);
		while (arr[i][++k])
		{
			if (arr[i][k] != '-' && !ft_isdigit(arr[i][k]))
				exit_error();
		}
		check_min_int(arr[i]);
		check_max_int(arr[i]);
		i++;
	}
	if (arr[1])
		check_duplicate(arr);
	if (DEV_MODE)
		ft_printf("\n\e[1;42mPASSED!\e[0m\n");
	return (TRUE);
}
