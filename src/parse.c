/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:24:33 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/27 17:25:20 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_stack(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (isadigit(argv[i]) == FALSE)
			error();
		if (islimits(argv[i]) == FALSE)
			error();
		i++;
	}
	if (isthesame(argv) == FALSE)
		error();
}

int	isadigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '2'
		|| str[i] == '3' || str[i] == '4' || str[i] == '5'
		|| str[i] == '6' || str[i] == '7' || str[i] == '8'
		|| str[i] == '9' || str[0] == '-' || str[0] == '+')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	islimits(char *str)
{
	long	i;

	i = atoi_ps(str);
	if (i < INT_MIN || i > INT_MAX)
		return(FALSE);
	return (TRUE);
}

int	isthesame(char **str)
{
	int		i;
	int		j;
	long	a;
	long	b;
	
	i = 0;
	while(str[i] != NULL)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			a = atoi_ps(str[i]);
			b = atoi_ps(str[j]);
			if (a == b)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

long	atoi_ps(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[0] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}