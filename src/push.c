/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:39:47 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/29 11:13:47 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	push_stack_ab(t_stack **stack_a, t_stack **stack_b, char cmd)
{
	if (cmd == 'a')
	{
		if (!(*stack_b))
			return ;
		ft_push(stack_a, ft_pop(stack_b));
		write(1, "pa\n", 3);
	}
	else if (cmd == 'b')
	{
		if (!(*stack_a))
			return ;
		ft_push(stack_b, ft_pop(stack_a));
		write(1, "pb\n", 3);
	}
}

void	ft_sort_bmin(t_stack **stack, int min)
{
	if ((*stack)->next->ind == min + 2)
	{
		rotate_b(stack);
		return ;
	}
	swap_b(stack);
	reverse_rotate_b(stack);
}

void	ft_sort_bmax(t_stack **stack, int min)
{
	if ((*stack)->next->ind == min)
	{
		reverse_rotate_b(stack);
		return ;
	}
	swap_b(stack);
}

void	reverse_rotate_b(t_stack **lst)
{
	if (ft_reverse_rotate(lst))
		return ;
	write(1, "rrb\n", 4);
}
