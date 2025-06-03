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

	num = LONG_MAX;
	i = 0;
	judge = 0;
	i = minus_judge_space_cut(str, &judge);
	if (str[i] >= '0' && str[i] <= '9')
		num = 0;//文字ガード、数字のみ受け入れ
	while (str[i] >= '0' && str[i] <= '9')
	{
		if((judge == 0 && num > INT_MAX) || (judge == 1 && num > (INT_MAX + 1)))
			return(LONG_MAX);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return(LONG_MAX);//文字ガード、数字のみ受け入れ
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
	target->prev = target;
	target->next = target;
	return (target);
}

int is_sorted(const t_stack *stack)
{
	t_node *ref;
	size_t i;

	i = 0;
	ref = stack->top;
	if(stack->size == 0 || stack->size == 1)
		return(1);
	while(i < (stack->size - 1))
	{
		if(ref->value > ref->next->value)
			return(0);
		ref = ref->next;
		i++;
	}
	return(1);
}

void node_free(t_stack *stack)
{
	t_node *next;
	if(stack->size == 0 || stack->top == NULL)
		return ;
	while(stack->size > 1)
	{
		next = stack->top->next;
		free(stack->top);
		stack->top = next;
		stack->size--;
	}
	free(stack->top);
	stack->top = NULL;
	stack->size--;
}

void stack_free(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a);
	free(stack_b);
}

int malloc_initialize_stack(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	if(*stack_a == NULL)
		return(-1);
	*stack_b = malloc(sizeof(t_stack));
	if(*stack_b == NULL)
	{
		free(*stack_a);
		return(-1);
	}
	(*stack_a)->size = 0;
	(*stack_a)->top = NULL;
	(*stack_b)->size = 0;
	(*stack_b)->top = NULL;
	return(0);
}
