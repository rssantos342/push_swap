/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:34:25 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/03 12:58:25 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_ac(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i + 1);
}

void	ft_ps_args(t_stack *stack_a, t_stack *stack_b, int ac)
{
	if (ac >= 2 && ac <= 5)
	{
		if (!ft_check_sorted(stack_a))
			sort_up_to_four(&stack_a, &stack_b);
	}
	else if (ac == 6)
		sort_five(&stack_a, &stack_b);
	else
		sort_above_five(&stack_a, &stack_b);
	ft_free_list(&stack_a);
}

void	ft_free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

t_stack	*ft_split_ac2(t_stack *stack_a, char **av, int flag, int *ac)
{
	av = ft_split(av[1], ' ');
	if (av[0] == 0)
	{
		ft_free_split(av);
		ft_error_exit(NULL, 1);
	}
	flag = 0;
	*ac = count_ac(av);
	ft_check_args(av, flag, 0);
	stack_a = ft_stack_init(av, 0);
	if (flag == 0)
	{
		ft_free_split(av);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;

	stack_a = NULL;
	stack_b = NULL;
	flag = 1;
	if (ac == 1)
		return (0);
	else if (av[1][0] == '\0')
		ft_error_exit(NULL, 1);
	else if (ac == 2 && ft_strchr(av[1], ' '))
	{
		stack_a = ft_split_ac2(stack_a, av, flag, &ac);
	}
	else
	{
		ft_check_args(av, flag, 1);
		stack_a = ft_stack_init(av, 1);
	}
	ft_check_dup(stack_a);
	ft_check_int(stack_a);
	ft_ps_args(stack_a, stack_b, ac);
}
