/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:55:59 by bcarlee           #+#    #+#             */
/*   Updated: 2022/01/02 16:35:37 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_min_rotate(t_stack **stack, int *min)
{
	stack[0]->flag = -1;
	(*min)++;
	rotate_a(&stack[0]);
}

void	ft_min_plus_rotate(t_stack **stack, int *min)
{
	swap_a(&stack[0]);
	ft_min_rotate(stack, min);
	ft_min_rotate(stack, min);
}
