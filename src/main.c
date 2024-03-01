/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:11:28 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/27 17:50:34 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
    t_stack  *a;
    t_stack  *b;
    
	a = NULL;
	b = NULL;
    if (argc == 1 || argc == 2)
        return (1);
	else
		parse_stack(argv + 1);
	create_stack(&a, argv + 1);
	push_swap(&a, &b);
	print_nb(a, 0);
	print_nb(b, 0);
	free_stack(&a);
	free_stack(&b);
    return (0);
}

void	print_nb(t_stack *stack, int i)
{
	if (stack == NULL)
		ft_printf("Stack is NULL\n");
	while (stack != NULL && i == 1)
	{
		ft_printf("nb = %d\n", stack->nb);
		ft_printf("target nb = %d\n", stack->target_node->nb);
		ft_printf("cost = %d\n", stack->push_cost);
		stack = stack->next;
	}
	while (stack != NULL && i == 0)
	{
		ft_printf("nb = %d\n", stack->nb);
		stack = stack->next;
	}
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

void    error(void)
{
    ft_printf("Error\n");
    exit (1);
}