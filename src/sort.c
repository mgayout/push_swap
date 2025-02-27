/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:09:53 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/14 13:29:08 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a, t_stack **b, t_stack **act)
{
	while ((*act)->push_cost != 0)
	{
		if ((*a)->nb != (*act)->nb)
		{
			if (stack_pos(*a, *act) < (stacksize(*a) / 2))
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
			(*act)->push_cost--;
		}
		if ((*b)->nb != (*act)->target_node->nb)
		{
			if (stack_pos(*b, (*act)->target_node) < (stacksize(*b) / 2))
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
			(*act)->push_cost--;
		}
	}
	push(a, b, 'b');
}

void	sort_three(t_stack **a)
{
	while (is_sorted(*a) == FALSE)
	{
		if ((*a)->nb < (*a)->next->nb && (*a)->nb < (*a)->next->next->nb)
		{
			swap(a, 'a');
			rotate(a, 'a');
		}
		else if ((*a)->nb > (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
			rotate(a, 'a');
		else if ((*a)->nb < (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
			reverse_rotate(a, 'a');
		else
			swap(a, 'a');
	}
}

void	clean_b(t_stack **a, t_stack **b)
{
	while (*b != NULL)
	{
		(*b)->target_node = find_closest_max((*b)->nb, a);
		while ((*b)->target_node->nb != (*a)->nb)
		{
			if (stack_pos(*a, (*b)->target_node) <= stacksize(*a) / 2)
				rotate(a, 'a');
			else if (stack_pos(*a, (*b)->target_node) > stacksize(*a) / 2)
				reverse_rotate(a, 'a');
		}
		push(b, a, 'a');
	}
}

int	stack_pos(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack != target)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

void	sort_a(t_stack **a)
{
	t_stack	*tmp;

	tmp = find_nb_min(*a);
	if (stack_pos(*a, tmp) <= (stacksize(*a) / 2))
		while (is_sorted(*a) == FALSE)
			rotate(a, 'a');
	else
		while (is_sorted(*a) == FALSE)
			reverse_rotate(a, 'a');
}
