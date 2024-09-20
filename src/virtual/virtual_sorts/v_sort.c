/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_sort.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 10:08:22 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/19 12:11:23 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

static void	v_sort_hundreds_a(t_ptr *ptr)
{
	ptr->steps = 0;
	if (ordered(ptr, 'a'))
		return (v_ordered_to_sorted(ptr, 'a'));
	if (count(ptr, 'a') <= 5)
		return (v_sort_five(ptr, 'a'));
	v_push_smallest_quantiles(ptr, 'a', 2);
	while (count(ptr, 'b') > 25)
		v_push_largest_quantiles(ptr, 'b', 4);
	while (count(ptr, 'a') > 5)
		v_push_smallest_quantiles(ptr, 'a', 3);
	v_sort_five(ptr, 'a');
	v_pull_min_max(ptr, 'a');
}

static void	v_sort_hundreds_b(t_ptr *ptr)
{
	ptr->steps = 0;
	if (ordered(ptr, 'a'))
		return (v_ordered_to_sorted(ptr, 'a'));
	if (count(ptr, 'a') <= 5)
		return (v_sort_five(ptr, 'a'));
	v_push_smallest_quantiles(ptr, 'a', 2);
	while (count(ptr, 'b') > 15)
		v_push_largest_quantiles(ptr, 'b', 4);
	while (count(ptr, 'a') > 5)
		v_push_smallest_quantiles(ptr, 'a', 3);
	v_sort_five(ptr, 'a');
	v_pull_min_max(ptr, 'a');
}

static void	v_sort_hundreds_c(t_ptr *ptr)
{
	ptr->steps = 0;
	if (ordered(ptr, 'a'))
		return (v_ordered_to_sorted(ptr, 'a'));
	if (count(ptr, 'a') <= 5)
		return (v_sort_five(ptr, 'a'));
	while (count(ptr, 'a') > 5)
		v_push_smallest_quantiles(ptr, 'a', 3);
	v_sort_five(ptr, 'a');
	v_pull_min_max(ptr, 'a');
}

void	v_sort(t_ptr *ptr, int i)
{
	if (i == 0)
		v_sort_hundreds_a(ptr);
	else if (i == 1)
		v_sort_hundreds_b(ptr);
	else if (i == 2)
		v_sort_hundreds_c(ptr);
}
