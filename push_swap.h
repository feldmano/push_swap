/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 21:58:10 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 12:50:34 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdarg.h> // argc, argv[] 
# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <stdio.h> // for testing long ints
# include <stdbool.h>
# include <limits.h> // for INT_MAX and INT_MIN
# include <math.h> // for NAN (double array sentinal value)

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prior;

}	t_node;

typedef struct s_ptr
{
	int		args;
	double	*array;
	double	*norm_array;
	char	**char_array;
	t_node	*a_top;
	t_node	*b_top;
	int		steps;

}	t_ptr;

//array utilities
void	free_dbl(char **array);
bool	populate_quoted(t_ptr *ptr);
bool	populate_un_quoted(t_ptr *ptr, char **argv, int argc);
bool	array_has_no_dupes(t_ptr *ptr);
bool	norm_array(t_ptr *ptr);
void	readout_a(double *array);

//stack utilities
bool	initialize(t_ptr *ptr);
void	free_stack(t_ptr *ptr, char c, int i);

//checkers
void	readout(t_ptr *ptr, char c);
int		min(t_ptr *ptr, char c);
int		max(t_ptr *ptr, char c);
int		count(t_ptr *ptr, char c);
bool	ordered(t_ptr *ptr, char c);
int		short_path_to_min(t_ptr *ptr, char c);
int		short_path_to_max(t_ptr *ptr, char c);
int		short_path_to_target_min_max(t_ptr *ptr, char c);
int		nearest_num_less_than_threshold(t_ptr *ptr, char c, double threshold);
int		nearest_num_more_than_threshold(t_ptr *ptr, char c, double threshold);

//stack ops
char	fetch_char(char c, int i);
t_node	*fetch_top(t_ptr *ptr, char c);
void	set_top_at_home(t_ptr *ptr, char home, t_node *new_top);
void	set_top_at_target(t_ptr *ptr, char target, t_node *top);
void	swap(t_ptr *ptr, char c);
void	sswap(t_ptr *ptr);
void	rotate(t_ptr *ptr, char c);
void	r_rotate(t_ptr *ptr, char c);
void	rr(t_ptr *ptr);
void	rrr(t_ptr *ptr);
void	push(t_ptr *ptr, char target);

//sorts
void	ordered_to_sorted(t_ptr *ptr, char c);
void	push_largest_quantiles(t_ptr *ptr, char c, double qtile);
void	push_smallest_quantiles(t_ptr *ptr, char c, double qtile);
void	pull_min_max(t_ptr *ptr, char c);
void	sort_three(t_ptr *ptr, char c);
void	sort_five(t_ptr *ptr, char c);
void	sort_hundreds_a(t_ptr *ptr);
void	sort_hundreds_b(t_ptr *ptr);
void	sort_hundreds_c(t_ptr *ptr);
bool	sort(t_ptr *ptr);

//virtual stack ops
void	v_swap(t_ptr *ptr, char c);
void	v_sswap(t_ptr *ptr);
void	v_rotate(t_ptr *ptr, char c);
void	v_r_rotate(t_ptr *ptr, char c);
void	v_rr(t_ptr *ptr);
void	v_rrr(t_ptr *ptr);
void	v_push(t_ptr *ptr, char target);

//virtual sorts
void	v_ordered_to_sorted(t_ptr *ptr, char c);
void	v_push_smallest_quantiles(t_ptr *ptr, char c, double qtile);
void	v_push_largest_quantiles(t_ptr *ptr, char c, double qtile);
void	v_pull_min_max(t_ptr *ptr, char c);
void	v_sort_three(t_ptr *ptr, char c);
void	v_sort_five(t_ptr *ptr, char c);
void	v_sort(t_ptr *ptr, int i);

#endif