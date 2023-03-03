/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:57:20 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/02/23 15:58:12 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *nptr)
{
	long int	i;
	long int	n;
	long int	signal;

	i = 0;
	n = 0;
	signal = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		signal *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = nptr[i] - 48 + (n * 10);
		i++;
	}
	return (n * signal);
}
