/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:05:38 by mgayout           #+#    #+#             */
/*   Updated: 2024/03/04 14:30:47 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_closest_min(int nb_a, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*copy;
	char	*nb;

	copy = *stack;
	nb = "a";
	while (copy != NULL)
	{
		if (ft_strncmp(nb, "a", 1) == 0 && copy->nb < nb_a)
		{
			nb = ft_itoa(copy->nb);
			copy = copy->next;
		}
		else if (ft_strncmp(nb, "a", 1) != 0
			&& copy->nb < nb_a && copy->nb > ft_atoi(nb))
		{
			free(nb);
			nb = ft_itoa(copy->nb);
			copy = copy->next;
		}
		else
			copy = copy->next;
	}
	tmp = find_closest_min2(nb, stack);
	return (tmp);
}

t_stack	*find_closest_min2(char *nb, t_stack **stack)
{
	t_stack	*tmp;

	if (ft_strncmp(nb, "a", 1) == 0)
		tmp = find_nb_max(*stack);
	else
	{
		tmp = find_stack(ft_atoi(nb), *stack);
		free(nb);
	}
	return (tmp);
}

t_stack	*find_closest_max(int nb_b, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*copy;
	char	*nb;

	copy = *stack;
	nb = "a";
	while (copy != NULL)
	{
		if (ft_strncmp(nb, "a", 1) == 0 && copy->nb > nb_b)
		{
			nb = ft_itoa(copy->nb);
			copy = copy->next;
		}
		else if (ft_strncmp(nb, "a", 1) != 0
			&& copy->nb > nb_b && copy->nb < ft_atoi(nb))
		{
			free(nb);
			nb = ft_itoa(copy->nb);
			copy = copy->next;
		}
		else
			copy = copy->next;
	}
	tmp = find_closest_max2(nb, stack);
	return (tmp);
}

t_stack	*find_closest_max2(char *nb, t_stack **stack)
{
	t_stack	*tmp;

	if (ft_strncmp(nb, "a", 1) == 0)
		tmp = find_nb_min(*stack);
	else
	{
		tmp = find_stack(ft_atoi(nb), *stack);
		free(nb);
	}
	return (tmp);
}

t_stack	*find_stack(int nb, t_stack *stack)
{
	t_stack	*tmp;

	tmp = NULL;
	while (stack != NULL)
	{
		if (nb == stack->nb)
		{
			tmp = stack;
			return (tmp);
		}
		else
			stack = stack->next;
	}
	return (tmp);
}
