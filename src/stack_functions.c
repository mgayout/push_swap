/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:36 by mgayout           #+#    #+#             */
/*   Updated: 2024/03/04 13:46:26 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack, char c)
{
	int	tmp1;
	int	tmp2;

	tmp1 = (*stack)->nb;
	tmp2 = (*stack)->next->nb;
	(*stack)->nb = tmp2;
	(*stack)->next->nb = tmp1;
	ft_printf("s%c\n", c);
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
	ft_printf("p%c\n", c);
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
	ft_printf("r%c\n", c);
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
	ft_printf("rr%c\n", c);
}
