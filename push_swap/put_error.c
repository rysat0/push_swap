/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:06:25 by rysato            #+#    #+#             */
/*   Updated: 2025/06/02 12:06:25 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_error_invalid()
{
	write(1, "Error\n", 6);
}

void put_error_free(int *array)
{
	free(array);
	write(1, "Error\n", 6);
}
