/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:58:30 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/01 16:32:57 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_args(char **av, int flag, int i)
{
	int	j;

	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' && av[i][j + 1])
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 1)
				j++;
			else
			{
				if (flag == 0)
				{
					ft_free_split(av);
				}
				ft_error_exit(NULL, 1);
			}
		}
		i++;
	}
}

void	ft_check_dup(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*head_a;

	head_a = stack_a;
	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (stack_a->data == temp->data)
			{
				ft_error_exit(head_a, 0);
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
}

int	ft_check_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	ft_check_pos(t_stack *lst, int target)
{
	int	i;

	i = 0;
	while (lst->data != target)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_check_int(t_stack *stack_a)
{
	t_stack	*head_a;

	head_a = stack_a;
	while (stack_a)
	{
		if (stack_a->data < -2147483648 || stack_a->data > 2147483647)
		{
			ft_error_exit(head_a, 0);
		}
		stack_a = stack_a->next;
	}
}
