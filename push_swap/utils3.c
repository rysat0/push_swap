/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:31:06 by rysato            #+#    #+#             */
/*   Updated: 2025/06/22 14:11:40 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_remain(t_stack *stack_a, int low, int high)
{
	int		count;
	int		i;
	t_node	*ref;

	count = 0;
	i = 0;
	ref = stack_a->top;
	while (i++ < stack_a->size)
	{
		if (ref->value >= low && ref->value <= high)
			count++;
		ref = ref->next;
	}
	return (count);
}
