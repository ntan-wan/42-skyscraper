/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_eliminate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:15:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/29 12:08:16 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

static void	process(t_cell **board, int i, int *row_dup, int *col_dup)
{
	int	j;
	int	*row;
	int	*col;

	j = -1;
	row = get_cell_indices_row_index(i / N);
	col = get_cell_indices_col_index(i % N);
	while (++j < TOTAL_COLS)
	{
		if ((*board)[i].nums[j])
		{
			*row_dup = duplicate_check(board, i, row, (*board)[i].nums[j]);
			*col_dup = duplicate_check(board, i, col, (*board)[i].nums[j]);
		}
		if (!(*row_dup) || !(*col_dup))
		{
			remove_all_left_one(board, i, (*board)[i].nums[j]);
			remove_duplicated_num(board, i, row, (*board)[i].nums[j]);
			remove_duplicated_num(board, i, col, (*board)[i].nums[j]);
		}
	}
	free(row);
	free(col);
}

void	process_elimination(t_cell **board)
{
	int	i;
	int	row_dup;
	int	col_dup;

	i = -1;
	while (++i < TOTAL_CELLS)
	{	
		if ((*board)[i].size > 1)
			process(board, i, &row_dup, &col_dup);
	}
	if (!row_dup || !col_dup)
		process_elimination(board);
}
