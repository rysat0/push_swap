/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:52:30 by rysato            #+#    #+#             */
/*   Updated: 2025/06/02 17:52:30 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int search_maxrank_index(const t_stack *stack)
{//size0ガードする？
	int i;
	int index;//返すmaxがあったindex(番目)
	int max_rank;//走査中の現段階でのmaxのrank(大きさ)
	const t_node *ref;//走査用ノード

	i = 1;
	index = 0;
	ref = stack->top;
	max_rank = ref->value;

	while(i < stack->size)
	{
		ref = ref->next;
		if(ref->value > max_rank)
		{
			max_rank = ref->value;
			index = i;
		}
		i++;
	}
	return(index);
}

static void rotate_shortest_b(t_stack *stack, int index)
{
	int half;

	half = (stack->size / 2);
	if(index <= half)
	{
		while(index > 0)
		{
			rb(stack);
			index--;
		}
	}
	else
	{
		while(index < stack->size)
		{
			rrb(stack);
			index++;
		}
	}
}

void push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int index;//Bの中で最大ランクが何番目か

	while(stack_b->size != 0)
	{
		index = search_maxrank_index(stack_b);
		if(index != 0)
			rotate_shortest_b(stack_b, index);
		pa(stack_a, stack_b);
	}
}
