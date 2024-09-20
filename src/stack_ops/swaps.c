/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/27 18:08:47 by opelman       #+#    #+#                 */
/*   Updated: 2024/08/23 16:24:23 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_ptr *ptr, char c)
{
	int		swap;
	t_node	*top;

	top = ptr->a_top;
	if (c == 'b')
		top = ptr->b_top;
	if (top->next == NULL)
		return ;
	swap = top->num;
	top->num = top->next->num;
	top->next->num = swap;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	sswap(t_ptr *ptr)
{
	int		swap;
	t_node	*top;

	top = ptr->a_top;
	if (top->next != NULL)
	{
		swap = top->num;
		top->num = top->next->num;
		top->next->num = swap;
	}
	top = ptr->b_top;
	if (top->next != NULL)
	{
		swap = top->num;
		top->num = top->next->num;
		top->next->num = swap;
	}
	write(1, "ss\n", 3);
}
