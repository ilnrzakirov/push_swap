/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:27:12 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/29 16:10:29 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_and_push(t_stack **stack, int pos, int len)
{
	if (pos < len - pos)
	{
		while (pos--)
			rotate_a(stack);
	}
	else
	{
		while (pos++ < len)
			reverse_rotate_a(stack);
	}
}

void	rotate_min(t_stack **stack, int len, int i)
{
	int		min;
	t_stack	*new;
	int		pos;

	new = (*stack);
	min = 2147483647;
	while (new)
	{
		if (new->nbr < min)
		{
			min = new->nbr;
			pos = i;
		}
		new = new->next;
		i++;
	}
	rotate_and_push(stack, pos, len);
}

void	rotate_b(t_stack **lst)
{
	if (ft_rotate(lst))
		return ;
	write(1, "rb\n", 3);
}

void	swap_b(t_stack **lst)
{
	if (swap(lst))
		return ;
	write(1, "sb\n", 3);
}
