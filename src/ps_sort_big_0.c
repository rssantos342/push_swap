/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:58:14 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/08 16:22:30 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_above_five(t_stack **stack_a, t_stack **stack_b)
{
	t_info	inf_a;
	t_info	a_nbr2sort;
	t_info	b_nbr_target;

	if (ft_check_sorted(*stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	inf_a.size = ft_lstsize_ps(*stack_a);
	while (inf_a.size > 3)
	{
		a_nbr2sort = nbr2move_sa(*stack_a, *stack_b, inf_a);
		a_nbr2sort.size = ft_lstsize_ps(*stack_a);
		b_nbr_target = target_nbr_sb(*stack_b, a_nbr2sort.data);
		b_nbr_target.size = ft_lstsize_ps(*stack_b);
		ft_sort(stack_a, stack_b, a_nbr2sort, b_nbr_target);
		inf_a.size = ft_lstsize_ps(*stack_a);
	}
	ft_sort_three(stack_a);
	put_all_a(stack_a, stack_b);
	ft_rotate_stack_a(stack_a);
}

t_info	nbr2move_sa(t_stack *stack_a, t_stack *stack_b, t_info inf_a)
{
	t_stack	*temp_a;
	t_info	nbr2move_sa;
	int		moves;
	int		cheaper_mvs;

	cheaper_mvs = 0;
	temp_a = stack_a;
	inf_a.index = 0;
	while (temp_a)
	{
		if (temp_a->data > ft_max(stack_b) || temp_a->data < ft_min(stack_b))
			moves = ft_min_max(stack_b, inf_a);
		else if (temp_a->data < ft_max(stack_b) && \
			temp_a->data > ft_min(stack_b))
			moves = btw_min_max(stack_b, temp_a->data, inf_a);
		if (cheaper_mvs > moves || inf_a.index == 0)
		{
			cheaper_mvs = moves;
			nbr2move_sa.index = inf_a.index;
			nbr2move_sa.data = temp_a->data;
		}
		inf_a.index++;
		temp_a = temp_a->next;
	}
	return (nbr2move_sa);
}

int	ft_min_max(t_stack *stack_b, t_info inf_a)
{
	t_info	inf_b;

	inf_b.size = ft_lstsize_ps(stack_b);
	inf_b.index = ft_check_pos(stack_b, ft_max(stack_b));
	return (nbr_moves(inf_a, inf_b));
}

int	btw_min_max(t_stack *stack_b, int data_a, t_info inf_a)
{
	t_stack	*temp_b;
	t_info	inf_b;
	int		min_b;

	temp_b = stack_b;
	min_b = ft_min(stack_b);
	inf_b.size = ft_lstsize_ps(stack_b);
	while (temp_b)
	{
		if (data_a > temp_b->data)
		{
			if (min_b < temp_b->data)
				min_b = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	inf_b.index = ft_check_pos(stack_b, min_b);
	return (nbr_moves(inf_a, inf_b));
}

int	nbr_moves(t_info inf_a, t_info inf_b)
{
	int	nbr_mvs;

	nbr_mvs = 0;
	if (inf_a.index > 0 && inf_b.index > 0)
	{
		nbr_mvs = ft_index_ab_above_0(inf_a, inf_b, nbr_mvs);
	}
	else
	{
		if (inf_a.index >= inf_a.size / 2)
			nbr_mvs = inf_a.size - inf_a.index;
		else if (inf_b.index >= inf_b.size / 2)
			nbr_mvs = inf_b.size - inf_b.index;
		else
			nbr_mvs = nbr_moves_aux(inf_a.index, inf_b.index);
	}
	return (nbr_mvs + 1);
}
