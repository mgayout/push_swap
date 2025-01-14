/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:36 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/14 13:40:48 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack, char c)
{
	int	tmp1;
	int	tmp2;

	tmp1 = (*stack)->nb;
	tmp2 = (*stack)->next->nb;
	(*stack)->nb = tmp2;
	(*stack)->next->nb = tmp1;
	if (!c)
		return;
	//ft_printf("s%c\n", c);
}

void	push(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	tmp = *a;
	if ((*a)->next == NULL)
		*a = NULL;
	else
	{
		*a = (*a)->next;
		(*a)->prev = NULL;
	}
	stackadd_front(b, tmp);
	if (!c)
		return;
	//ft_printf("p%c\n", c);
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp2 = *stack;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (!c)
		return;
	//ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp;
	stackadd_front(stack, tmp2);
	tmp2 = (*stack)->next;
	while (tmp2->next != *stack)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	if (!c)
		return;
	//ft_printf("rr%c\n", c);
}
