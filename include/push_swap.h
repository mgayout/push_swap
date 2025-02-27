/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:12:22 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/14 13:38:32 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf-main/include/ft_printf.h"
# include "../ft_printf-main/libft-main/include/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

# define TRUE 0
# define FALSE 1

typedef struct s_stack
{
	int				nb;
	int				push_cost;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//MAIN

void	main2(t_stack *a, t_stack *b, char **argv);
void	free_stack(t_stack **s);
void	error(void);
void	print_nb(t_stack *s);

//STACK_INIT

void	create_stack(t_stack **s, char **str);
void	fill_stack(t_stack **stack, int nb);

//PARSE

void	parse_stack(char **argv);
int		isadigit(char *str);
int		islimits(char *str);
int		isthesame(char **str);
long	atoi_ps(char *str);

//STACK_FUNCTIONS

void	swap(t_stack **stack, char c);
void	push(t_stack **a, t_stack **b, char c);
void	rotate(t_stack **stack, char c);
void	reverse_rotate(t_stack **stack, char c);

//LST_FUNCTIONS

t_stack	*stacklast(t_stack *stack);
int		stacksize(t_stack *stack);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stackadd_front(t_stack **stack, t_stack *new);

//PUSH_SWAP

void	push_swap(t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
void	set_target(t_stack *a, t_stack *b);
t_stack	*find_nb_max(t_stack *stack);
t_stack	*find_nb_min(t_stack *stack);

//STACK_TARGET

t_stack	*find_closest_min(int nb_a, t_stack **stack);
t_stack	*find_closest_min2(char *nb, t_stack **stack);
t_stack	*find_closest_max(int nb_b, t_stack **stack);
t_stack	*find_closest_max2(char *nb, t_stack **stack);
t_stack	*find_stack(int nb, t_stack *stack);

//STACK_COST

void	set_cost(t_stack *a, t_stack *b);
long	push_cost(t_stack *a, t_stack *b, t_stack *elem);
t_stack	*compare_cost(t_stack *a);

//SORT

void	sort(t_stack **a, t_stack **b, t_stack **act);
void	sort_three(t_stack **a);
void	clean_b(t_stack **a, t_stack **b);
int		stack_pos(t_stack *stack, t_stack *target);
void	sort_a(t_stack **a);

#endif