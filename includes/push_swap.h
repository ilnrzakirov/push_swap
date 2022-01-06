/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:26:05 by bcarlee           #+#    #+#             */
/*   Updated: 2022/01/02 17:01:12 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stack{
	int				nbr;
	int				ind;
	int				flag;
	struct s_stack	*next;
}					t_stack;
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
int		ft_atoi(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *str, unsigned int s, size_t l);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	print_error(void);
int		ft_isdigit_char(char *arr_av, int i);
void	ft_check_dup2(t_stack *stack_a, int count, int i);
void	get_index(t_stack *stack_a, int *arr, int i);
int		check_sort_stack(t_stack **stack_a);
int		swap(t_stack **stack);
void	ft_push(t_stack **lst, t_stack *new);
t_stack	*ft_pop(t_stack **lst);
void	swap_a(t_stack **lst);
void	sort_3(t_stack **stack, int a, int b, int c);
void	rotate_a(t_stack **lst);
void	reverse_rotate_a(t_stack **lst);
int		ft_rotate(t_stack **lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_reverse_rotate(t_stack **lst);
void	mid_sort(t_stack **stack_a, t_stack **stack_b, int i);
void	rotate_min(t_stack **stack, int len, int i);
void	push_stack_ab(t_stack **stack_a, t_stack **stack_b, char cmd);
int		get_size_stack(t_stack *stack);
int		div_stack(t_stack **stack, int min, int max);
int		push_mid_ind(t_stack **stack, int mid, int ab);
void	big_sort(t_stack **stack, int max, int min);
int		div_b(t_stack **stack, int min, int max, int i);
void	rotate_b(t_stack **lst);
int		sort_div(t_stack **stack, int min);
void	swap_b(t_stack **lst);
void	ft_sort_bmin(t_stack **stack, int min);
void	ft_sort_bmax(t_stack **stack, int min);
void	reverse_rotate_b(t_stack **lst);
void	sort_3_b(t_stack **stack, int min);
int		sort_a_and_push(t_stack **stack, int ret);
int		ft_quick_check(t_stack **stack);
void	ft_min_rotate(t_stack **stack, int *min);
void	ft_min_plus_rotate(t_stack **stack, int *min);
int		ft_push_back_b(t_stack **stack, int *min);
#endif