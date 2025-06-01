/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:32:19 by rysato            #+#    #+#             */
/*   Updated: 2025/06/01 21:54:23 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>


typedef struct s_node
{
	ssize_t			value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;
//リストを構成する一つ一つの値

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;
//リストを管理する役割
//循環リストの先頭を常に指している

long	ft_atol(const char *str);
void	push_first(t_stack *stack, t_node *target);
t_node	*make_new_node(int value);
