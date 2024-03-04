/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:11:28 by mgayout           #+#    #+#             */
/*   Updated: 2024/03/04 13:58:25 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == 2)
		return (0);
	else
		parse_stack(argv + 1);
	create_stack(&a, argv + 1);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
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

/*void	print_nb(t_stack *stack)
{
	if (stack == NULL)
		ft_printf("Stack is NULL\n");
	while (stack != NULL)
	{
		ft_printf("nb = %d\n", stack->nb);
		stack = stack->next;
	}
}*/
