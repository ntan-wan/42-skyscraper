/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_eliminate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:15:57 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/28 22:42:52 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

static int	duplicate_check(t_cell **board, int cell_index, int *row_col, int num)
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < TOTAL_COLS)
		{
			if (row_col[i] != cell_index && (*board)[row_col[i]].nums[j] == num)
				return (1);
		}
	}
	return (0);
}

void	clear_all_left_one(t_cell **board, int cell_index, int num)
{
	int	i;

	i = -1;
	while (++i < TOTAL_COLS)
	{
		if ((*board)[cell_index].nums[i] != num)
			(*board)[cell_index].nums[i] = 0;
	}
}

void	process_elimination(t_cell **board)
{
	int	i;
	int	j;
	int	*row;
	int	*col;
	int	row_dup;
	int	col_dup;

	i = -1;
	row_dup = 0;
	col_dup = 0;
	while (++i < TOTAL_CELLS)
	{	
		if (!is_one_value((*board)[i].nums))
		 {
			j = -1;
			row = get_cell_indices_row_index(i / N);
			col = get_cell_indices_col_index(i % N);
			while (++j < TOTAL_COLS)
			{
				if ((*board)[i].nums[j])
				{
					row_dup = duplicate_check(board, i,row, (*board)[i].nums[j]);
					col_dup = duplicate_check(board, i, col, (*board)[i].nums[j]);
				}
				if (!row_dup || !col_dup)
				{
					clear_all_left_one(board, i, (*board)[i].nums[j]);
					remove_num(board, row, (*board)[i].nums[j], i);
					remove_num(board, col, (*board)[i].nums[j], i);
				}
			}
			free(row);
			free(col);
		 }
	}
	if (!row_dup || !col_dup)
		process_elimination(board);
}