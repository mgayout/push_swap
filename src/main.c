/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:11:28 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/20 11:08:56 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		main2(a, b, argv);
	else
		parse_stack(argv + 1);
	create_stack(&a, argv + 1);
	push_swap(&a, &b);
	print_nb(a);
	print_nb(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	main2(t_stack *a, t_stack *b, char **argv)
{
	int		i;

	i = 0;
	argv = ft_split(argv[1], ' ');
	parse_stack(argv);
	create_stack(&a, argv);
	push_swap(&a, &b);
	print_nb(a);
	print_nb(b);
	free_stack(&a);
	free_stack(&b);
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	exit (1);
}

void	free_stack(t_stack **s)
{
	t_stack	*clean;

	while (*s != NULL)
	{
		clean = *s;
		*s = (*s)->next;
		free(clean);
	}
}

void	error(void)
{
	ft_printf("Error\n");
	exit (1);
}

void	print_nb(t_stack *stack)
{
	if (stack == NULL)
		ft_printf("Stack is NULL\n");
	while (stack != NULL)
	{
		/*if (stack->nb >= 0 && stack->nb < 10)
			ft_printf("nb = %d      | ", stack->nb);
		else if (stack->nb >= -9 && stack->nb < 99)
			ft_printf("nb = %d     | ", stack->nb);
		else if (stack->nb >= -99 && stack->nb < 999)
			ft_printf("nb = %d    | ", stack->nb);
		else if (stack->nb >= -999 && stack->nb < 9999)
			ft_printf("nb = %d   | ", stack->nb);
		else if (stack->nb >= -9999 && stack->nb < 99999)
			ft_printf("nb = %d  | ", stack->nb);
		else
			ft_printf("nb = %d | ", stack->nb);*/
		ft_printf("nb = %d | ", stack->nb);
		stack = stack->next;
	}
}
