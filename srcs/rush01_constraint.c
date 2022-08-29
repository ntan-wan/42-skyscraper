/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_constraint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:53:12 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/29 12:36:01 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

void	propagate_constraint(t_cell **board)
{
	int	i;
	int	j;
	int	*row;
	int	*col;
	int	removed;

	i = -1;
	removed = 0;
	while (++i < TOTAL_CELLS)
	{	
		if ((*board)[i].size == 1)
		{
			j = -1;
			while ((*board)[i].nums[++j] == 0)
				;
			row = get_cell_indices_row_index(i / N);
			col = get_cell_indices_col_index(i % N);
			removed += remove_dup_num(board, i, row, (*board)[i].nums[j]);
			removed += remove_dup_num(board, i, col, (*board)[i].nums[j]);
			free(row);
			free(col);
		}
	}
	if (removed)
		propagate_constraint(board);
}
