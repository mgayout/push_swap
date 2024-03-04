/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:14:32 by mgayout           #+#    #+#             */
/*   Updated: 2024/03/04 14:16:18 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*act;

	while (is_sorted(*a) == FALSE)
	{
		while (stacksize(*a) > 3 && stacksize(*b) != 2)
			push(a, b, 'b');
		while (stacksize(*a) > 3)
		{
			set_target(*a, *b);
			set_cost(*a, *b);
			act = compare_cost(*a);
			sort(a, b, &act);
		}
		if (stacksize(*a) == 3 && stacksize(*b) != 0)
		{
			sort_three(a);
			clean_b(a, b);
			sort_a(a);
		}
		if (stacksize(*a) == 3 && stacksize(*b) == 0)
			sort_three(a);
		if (stacksize(*a) == 2)
			swap(a, 'a');
	}
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack;
		stack = stack->next;
		if (tmp->nb > stack->nb)
			return (FALSE);
	}
	return (TRUE);
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	while (a->next != NULL)
	{
		tmp = find_closest_min(a->nb, &b);
		a->target_node = tmp;
		a = a->next;
	}
	tmp = find_closest_min(a->nb, &b);
	a->target_node = tmp;
}

t_stack	*find_nb_max(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack != NULL)
	{
		if (tmp->nb < stack->nb)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}

t_stack	*find_nb_min(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack != NULL)
	{
		if (tmp->nb > stack->nb)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}
