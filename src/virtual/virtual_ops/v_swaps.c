/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_swaps.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/27 18:08:47 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 09:47:50 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	v_swap(t_ptr *ptr, char c)
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
	ptr->steps++;
}

void	v_sswap(t_ptr *ptr)
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
	ptr->steps++;
}
