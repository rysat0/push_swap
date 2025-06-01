/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:28:11 by rysato            #+#    #+#             */
/*   Updated: 2025/06/01 19:35:50 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	minus_judge_space_cut(const char *str, int *judge)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*judge = 1;
		i++;
	}
	return (i);
}

long	ft_atol(const char *str)
{
	int			i;
	long long	num;
	int			judge;

	num = 0;
	i = 0;
	judge = 0;
	i = minus_judge_space_cut(str, &judge);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (judge == 1)
		num = -num;
	return ((long)num);
}

t_node	*make_new_node(int value)
{
	t_node	*target;

	target = malloc(sizeof(t_node));
	if (target == NULL)
		return (NULL);
	target->value = value;
	target->next = target;
	target->next = target;
	return (target);
}
