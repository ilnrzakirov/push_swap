/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:29:06 by bcarlee           #+#    #+#             */
/*   Updated: 2022/01/05 16:29:31 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_list_string(char *argv, t_stack **stack_a)
{
	char	**arr;
	int		i;
	int		j;

	*stack_a = NULL;
	arr = ft_split(argv, ' ');
	i = 0;
	while (arr[i])
		i++;
	j = i;
	while (--i >= 0 && ft_isdigit_char(arr[i], -1))
	{
		ft_lstadd_front(stack_a, ft_lstnew(ft_atoi(arr[i])));
		free(arr[i]);
	}
	free(arr);
	return (j);
}

int	stack_list_arr(char **argv, t_stack **stack_a, int j)
{
	int	i;

	*stack_a = NULL;
	i = j - 1;
	while (j-- > 1 && ft_isdigit_char(argv[j], -1))
	{
		ft_lstadd_front(stack_a, ft_lstnew(ft_atoi(argv[j])));
	}
	return (i);
}

void	small_sort(t_stack **stack, int i)
{
	if (i == 2)
	{
		swap_a(stack);
		exit (0);
	}
	else if (i == 3)
	{
		sort_3(stack, 0, 0, 0);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	int		count;
	int		i;
	t_stack	*stack[2];

	stack[1] = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		count = stack_list_string(argv[1], &stack[0]);
	else
		count = stack_list_arr(argv, &stack[0], argc);
	ft_check_dup2(stack[0], count, 0);
	if (!check_sort_stack(&stack[0]))
		return (0);
	if (count < 4)
		small_sort(&stack[0], count);
	else if (count < 8)
		mid_sort(&stack[0], &stack[1], count);
	else
	{
		i = div_stack(stack, 0, count - 1);
		big_sort(stack, i, 0);
	}
	return (0);
}
