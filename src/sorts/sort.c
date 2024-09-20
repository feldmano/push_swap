/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 10:15:33 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/19 12:08:12 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	void	choose_hundreds(t_ptr *ptr, int *count)
{
	if (count[0] <= count[1] && count[0] <= count[2])
		sort_hundreds_a(ptr);
	else if (count[1] <= count[0] && count[1] <= count[2])
		sort_hundreds_b(ptr);
	else if (count[2] <= count[0] && count[2] <= count[1])
		sort_hundreds_c(ptr);
}

bool	sort(t_ptr *ptr)
{
	int	*count;
	int	i;

	count = (int [3]){};
	i = -1;
	while (++i <= 3)
	{
		ptr->steps = 0;
		if (initialize(ptr) == false)
			return (false);
		if (i < 3)
		{
			v_sort(ptr, i);
			count[i] = ptr->steps;
			free_stack(ptr, 'a', ptr->args);
		}
	}
	choose_hundreds(ptr, count);
	return (free_stack(ptr, 'a', ptr->args), true);
}
