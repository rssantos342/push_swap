/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:44:47 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/02 10:52:24 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	b_target(t_stack *stack_b, int data_a)
{
	t_stack	*temp_b;
	t_info	b_target;

	temp_b = stack_b;
	if (data_a > ft_max(stack_b) || data_a < ft_min(stack_b))
	{
		b_target.data = ft_max(stack_b);
		b_target.index = ft_check_pos(stack_b, b_target.data);
		return (b_target);
	}
	else
		b_target.data = ft_min(stack_b);
	while (temp_b)
	{
		if (data_a > temp_b->data)
		{
			if (b_target.data < temp_b->data)
				b_target.data = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	b_target.index = ft_check_pos(stack_b, b_target.data);
	return (b_target);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, \
				t_info a_nbr2sort, t_info b_target)
{
	ab_top(stack_a, stack_b, a_nbr2sort, b_target);
	if ((*stack_a)->data == a_nbr2sort.data && \
			(*stack_b)->data != b_target.data)
		b_top(stack_b, b_target);
	else if ((*stack_a)->data != a_nbr2sort.data && \
				(*stack_b)->data == b_target.data)
		a_top(stack_a, a_nbr2sort);
	ft_pb(stack_a, stack_b);
}

void	ab_top(t_stack **stack_a, t_stack **stack_b, \
				t_info a_nbr2sort, t_info b_target)
{
	while ((*stack_a)->data != a_nbr2sort.data && \
			(*stack_b)->data != b_target.data)
	{
		if (a_nbr2sort.index > a_nbr2sort.size / 2 && \
				b_target.index > b_target.size / 2)
			ft_rrr(stack_a, stack_b);
		else if (a_nbr2sort.index < a_nbr2sort.size / 2 && \
				b_target.index > b_target.size / 2)
			ft_ra(stack_a, 0);
		else if (a_nbr2sort.index > a_nbr2sort.size / 2 && \
				b_target.index < b_target.size / 2)
			ft_rb(stack_b, 0);
		else
			ft_rr(stack_a, stack_b);
	}
}

void	b_top(t_stack **stack_b, t_info b_target)
{
	while ((*stack_b)->data != b_target.data)
	{
		if (b_target.index > b_target.size / 2)
			ft_rrb(stack_b, 0);
		else
			ft_rb(stack_b, 0);
	}
}

void	a_top(t_stack **stack_a, t_info a_nbr2sort)
{
	while ((*stack_a)->data != a_nbr2sort.data)
	{
		if (a_nbr2sort.index > a_nbr2sort.size / 2)
			ft_rra(stack_a, 0);
		else
			ft_ra(stack_a, 0);
	}
}
