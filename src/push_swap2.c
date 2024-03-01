/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:12 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/27 19:07:59 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    set_cost(t_stack *a, t_stack *b)
{
	t_stack	*copy;
    long cost;
    
	copy = a;
    while (a->next != NULL)
	{
		cost = push_cost(copy, b, a);
		a->push_cost = cost;
		a = a->next;
	}
    cost = push_cost(copy, b, a);
	a->push_cost = cost;
}

long    push_cost(t_stack *a, t_stack *b, t_stack *elem)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
    int cost_a;
    int cost_b;

    cost_a = 0;
    cost_b = 0;
	tmpa = a;
	tmpb = b;
    while (tmpa != elem)
    {
        cost_a++;
        tmpa = tmpa->next;
    }
    if (cost_a >= (stacksize(a) / 2))
		cost_a = stacksize(a) - cost_a;
    while (tmpb->nb != elem->target_node->nb)	
    {
        cost_b++;
        tmpb = tmpb->next;
    }
    if (cost_b >= (stacksize(b) / 2))
        cost_b = stacksize(b) - cost_b;
    return (cost_a + cost_b);
}

t_stack	*compare_cost(t_stack *a)
{
	t_stack	*tmp;
	
	tmp = a;
	while (a->next != NULL)
	{
		if (tmp->push_cost > a->push_cost)
			tmp = a;
		a = a->next;
	}
	return (tmp);
}