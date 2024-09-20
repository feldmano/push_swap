/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 18:09:10 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/13 14:27:29 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	short_path_to_target_min_max(t_ptr *ptr, char c)
{
	t_node	*top;	
	int		steps;
	int		temp;

	steps = 0;
	top = fetch_top(ptr, fetch_char(c, 1));
	if (top->num == min(ptr, c) - 1 || top->num == max(ptr, c) + 1)
		return (0);
	while (top->num != min(ptr, c) - 1 && top->num != max(ptr, c) + 1)
	{
		top = top->next;
		steps++;
	}
	temp = steps;
	top = top->prior;
	steps--;
	while (top->num != min(ptr, c) - 1 && top->num != max(ptr, c) + 1)
	{
		top = top->prior;
		steps--;
	}
	if (-1 * steps < temp)
		return (-1);
	return (1);
}

int	nearest_num_less_than_threshold(t_ptr *ptr, char c, double threshold)
{
	t_node	*top;
	int		steps;
	int		temp;

	steps = 0;
	top = fetch_top(ptr, c);
	if (top->num <= threshold)
		return (0);
	while (top->num > threshold)
	{
		top = top->next;
		steps++;
	}
	temp = steps;
	top = top->prior;
	steps--;
	while (top->num > threshold)
	{
		top = top->prior;
		steps--;
	}
	if (temp < -1 * steps)
		return (1);
	return (-1);
}

int	nearest_num_more_than_threshold(t_ptr *ptr, char c, double threshold)
{
	t_node	*top;
	int		steps;
	int		temp;

	steps = 0;
	top = fetch_top(ptr, c);
	if (top->num >= threshold)
		return (0);
	while (top->num < threshold)
	{
		top = top->next;
		steps++;
	}
	temp = steps;
	top = top->prior;
	steps--;
	while (top->num < threshold)
	{
		top = top->prior;
		steps--;
	}
	if (temp < -1 * steps)
		return (1);
	return (-1);
}

int	short_path_to_min(t_ptr *ptr, char c)
{
	t_node	*top;	
	int		steps;
	int		temp;

	top = fetch_top(ptr, c);
	if (top->num == min(ptr, c))
		return (0);
	steps = 0;
	while (top->num != min(ptr, c))
	{
		top = top->next;
		steps++;
	}
	temp = steps;
	top = top->prior;
	steps--;
	while (top->num != min(ptr, c))
	{
		top = top->prior;
		steps--;
	}
	if (-1 * steps < temp)
		return (-1);
	return (1);
}

int	short_path_to_max(t_ptr *ptr, char c)
{
	t_node	*top;	
	int		steps;
	int		temp;

	top = fetch_top(ptr, c);
	if (top->num == max(ptr, c))
		return (0);
	steps = 0;
	while (top->num != max(ptr, c))
	{
		top = top->next;
		steps++;
	}
	temp = steps;
	top = top->prior;
	steps--;
	while (top->num != max(ptr, c))
	{
		top = top->prior;
		steps--;
	}
	if (-1 * steps < temp)
		return (-1);
	return (1);
}
