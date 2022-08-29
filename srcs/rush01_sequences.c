/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_sequences.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:30:20 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/29 16:30:19 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

/*void	find_correct_sequence(t_cell **board, int *cell_indices)
{
	int	i;
	int	j;
	int	nums_count;
	int	highest_count;
	int	*sequences;
	int	blocks;

	i = -1;
	highest_count = INT_MIN;
	while (++i < TOTAL_COLS)
	{
		j = -1;
		nums_count = 0;
		while (++j < TOTAL_COLS)
		{
			if ((*board)[i].nums[j] != 0)
				nums_count++;
		}
		if (nums_count > highest_count)
			highest_count = nums_count;
	}
	blocks = highest_count * N + highest_count;
	sequences = malloc(sizeof(int) * blocks);
	//while (blocks && blocks % (N + 1) == 0)
	//{
	//	sequences[blocks - 1] = 0;
	//	blocks %= (N + 1);
	//}
	while (blocks--)
		sequences[blocks] = 0;
	i = -1;
	int	target_index;
	while (++i < TOTAL_COLS)
	{
		int k = 0;
		if (cell_is_one_value((*board)[cell_indices[i]].nums))
		{
			j = -1;
			while (++j < TOTAL_COLS)
			{
				if ((*board)[cell_indices[i]].nums[j] != 0)
					break ;
			}
			while (highest_count - k)
			{
				target_index = i + (k * (N + 1));
				sequences[target_index] = (*board)[cell_indices[i]].nums[j];
				k++;
			}
		}
		else
		{
			int	l;
			int	m;
			int n;
			
			l = -1;
			while ( ++l < TOTAL_COLS)
			{
				m = 0;
				if ((*board)[cell_indices[i]].nums[l] != 0)
				{
					n = -1;
					while (sequences[++n])
					{
						if (sequences[n] == (*board)[cell_indices[i].nums[l]])
						{
							
						}
					}
					sequences[n] = (*board)[cell_indices[i]].nums[l];
				}
			}
		}
	}
}*/

/*

void	sequences_filtration(t_cell **board)
{
	int i;
	int	j;
	int	*cell_indices;
	int	multiple_values;

	i = -1;
	multiple_values = 0;
	while ( ++i < TOTAL_ROWS)
	{
		j = -1;
		cell_indices = get_cell_indices_row_index(i);
		while (++j < TOTAL_COLS)
		{
			if (!cell_is_one_value((*board)[cell_indices[i]].nums))
				multiple_values = 1;
		}
		if (multiple_values)
			find_correct_sequence(board, cell_indices);
		free(cell_indices);
	}
	//i >= (2 * N) && i < (3 * N)
	//i >= (3 * N) && i < (TOTAL_CELLS);
}*/