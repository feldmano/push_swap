/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filters.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/17 10:12:51 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/19 12:11:07 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_smallest_quantiles(t_ptr *ptr, char c, double qtile)
{
	double	threshold;
	int		target;

	if (fetch_top(ptr, c) == NULL)
		return ;
	target = fetch_char(c, 1);
	threshold = min(ptr, c) + (1 / qtile) * (max(ptr, c) - min(ptr, c));
	while (count(ptr, c) != 0 && min(ptr, c) <= threshold)
	{
		if (nearest_num_less_than_threshold(ptr, c, threshold) == 0)
		{
			push(ptr, target);
			if (fetch_top(ptr, c)->num >= max(ptr, c) * 0.9 \
			&& fetch_top(ptr, target) \
			&& fetch_top(ptr, target)->num <= threshold / (2 * qtile))
				rr(ptr);
			else if (fetch_top (ptr, target)->num <= threshold / (2 * qtile))
				rotate(ptr, target);
		}
		else if (nearest_num_less_than_threshold(ptr, c, threshold) == 1)
			rotate(ptr, c);
		else if (nearest_num_less_than_threshold(ptr, c, threshold) == -1)
			r_rotate(ptr, c);
	}
}

void	push_largest_quantiles(t_ptr *ptr, char c, double qtile)
{
	double	threshold;
	int		target;

	if (fetch_top(ptr, c) == NULL)
		return ;
	target = fetch_char(c, 1);
	threshold = max(ptr, c) - (1 / qtile) * (max(ptr, c) - min(ptr, c));
	while (count(ptr, c) != 0 && max(ptr, c) >= threshold)
	{
		if (nearest_num_more_than_threshold(ptr, c, threshold) == 0)
		{
			push(ptr, target);
			if (fetch_top(ptr, c)->next->num < 0.5 * threshold \
			&& fetch_top(ptr, target)->num > fetch_top(ptr, target)->next->num)
				sswap(ptr);
		}
		else if (nearest_num_more_than_threshold(ptr, c, threshold) == 1)
			rotate(ptr, c);
		else if (nearest_num_more_than_threshold(ptr, c, threshold) == -1)
			r_rotate(ptr, c);
	}
}

void	pull_min_max(t_ptr *ptr, char c)
{
	char	source;

	source = fetch_char(c, 1);
	if (fetch_top(ptr, source) == NULL)
		return ;
	while (fetch_top(ptr, source) != NULL)
	{
		if (short_path_to_target_min_max(ptr, c) == 0)
			push(ptr, c);
		else if (short_path_to_target_min_max(ptr, c) == 1)
			rotate(ptr, source);
		else if (short_path_to_target_min_max(ptr, c) == -1)
			r_rotate(ptr, source);
	}
}
