/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:04:34 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/02 17:03:58 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_up_to_four(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = ft_lstsize_ps(*stack_a);
	if (size_a == 2)
		ft_sa(stack_a, 0);
	else if (size_a == 3)
		ft_sort_three(stack_a);
	else if (size_a == 4)
		ft_sort_four(stack_a, stack_b);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && b < c && a < c)
		ft_sa(stack_a, 0);
	else if (a > b && b > c && a > c)
	{
		ft_sa(stack_a, 0);
		ft_rra(stack_a, 0);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack_a, 0);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack_a, 0);
		ft_ra(stack_a, 0);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack_a, 0);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (ft_check_sorted(*stack_a))
		return ;
	i = index_min_sa(stack_a);
	min_four(stack_a, stack_b, i);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	min_four(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i == 0)
		ft_pb(stack_a, stack_b);
	else if (i == 1)
	{
		ft_ra(stack_a, 0);
		if (ft_check_sorted(*stack_a))
			return ;
		ft_pb(stack_a, stack_b);
	}
	else if (i == 2)
	{
		ft_ra(stack_a, 0);
		ft_ra(stack_a, 0);
		if (ft_check_sorted(*stack_a))
			return ;
		ft_pb(stack_a, stack_b);
	}
	else if (i == 3)
	{
		ft_rra(stack_a, 0);
		if (ft_check_sorted(*stack_a))
			return ;
		ft_pb(stack_a, stack_b);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (ft_check_sorted(*stack_a))
		return ;
	i = index_min_sa(stack_a);
	min_five(stack_a, stack_b, i);
	i = index_min_sa(stack_a);
	min_four(stack_a, stack_b, i);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
