/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_hundreds.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 17:23:02 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 12:56:15 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_hundreds_a(t_ptr *ptr)
{
	if (ordered(ptr, 'a'))
		return (ordered_to_sorted(ptr, 'a'));
	if (count(ptr, 'a') <= 5)
		return (sort_five(ptr, 'a'));
	push_smallest_quantiles(ptr, 'a', 2);
	while (count(ptr, 'b') > 15)
		push_largest_quantiles(ptr, 'b', 4);
	while (count(ptr, 'a') > 5)
		push_smallest_quantiles(ptr, 'a', 3);
	sort_five(ptr, 'a');
	pull_min_max(ptr, 'a');
}

void	sort_hundreds_b(t_ptr *ptr)
{
	ptr->steps = 0;
	if (ordered(ptr, 'a'))
		return (ordered_to_sorted(ptr, 'a'));
	if (count(ptr, 'a') <= 5)
		return (sort_five(ptr, 'a'));
	push_smallest_quantiles(ptr, 'a', 2);
	while (count(ptr, 'b') > 25)
		push_largest_quantiles(ptr, 'b', 4);
	while (count(ptr, 'a') > 5)
		push_smallest_quantiles(ptr, 'a', 3);
	sort_five(ptr, 'a');
	pull_min_max(ptr, 'a');
}

void	sort_hundreds_c(t_ptr *ptr)
{
	ptr->steps = 0;
	if (ordered(ptr, 'a'))
		return (ordered_to_sorted(ptr, 'a'));
	if (count(ptr, 'a') <= 5)
		return (sort_five(ptr, 'a'));
	while (count(ptr, 'a') > 5)
		push_smallest_quantiles(ptr, 'a', 3);
	sort_five(ptr, 'a');
	pull_min_max(ptr, 'a');
}
