/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:29:09 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/26 15:52:56 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_pop(t_stack **lst)
{
	t_stack	*el;

	if (!lst || !(*lst))
		return (NULL);
	el = *lst;
	*lst = el->next;
	el->next = NULL;
	return (el);
}

void	ft_push(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack) || (*stack)->next == NULL)
		return (1);
	tmp = ft_pop(stack);
	tmp2 = ft_pop(stack);
	ft_push(stack, tmp);
	ft_push(stack, tmp2);
	return (0);
}

void	swap_a(t_stack **lst)
{
	if (swap(lst))
		return ;
	write(1, "sa\n", 3);
}

void	rotate_a(t_stack **lst)
{
	if (ft_rotate(lst))
		return ;
	write(1, "ra\n", 3);
}
