/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:21:27 by mgayout           #+#    #+#             */
/*   Updated: 2024/03/04 13:47:15 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack(t_stack **stack, char **str)
{
	int		i;
	int		nb;

	i = 0;
	while (str[i])
	{
		nb = atoi_ps(str[i]);
		fill_stack(stack, nb);
		i++;
	}
}

void	fill_stack(t_stack **stack, int nb)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = nb;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stacklast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
