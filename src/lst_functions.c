/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:22:17 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/27 16:27:46 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stacklast(t_stack *stack)
{
	t_stack	*last;
	int		i;
	int		j;

	last = stack;
	if (!last)
		return (NULL);
	i = 1;
	j = stacksize(last);
	while (i != j)
	{
		last = last->next;
		i++;
	}
	return (last);
}

int	stacksize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*back;

	if (!*stack)
		*stack = new;
	else
	{
		back = stacklast(*stack);
		back->next = new;
	}
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (stacksize(*stack) == 0)
	{
		*stack = new;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		
		new->next = *stack;
		(*stack)->prev = new;
		new->prev = NULL;
		*stack = new;
	}
}