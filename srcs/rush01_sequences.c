/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_sequences.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:30:20 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/30 01:28:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

static int is_in_order(t_cell **board, int *row_col)
{
	int	i;

	i = -1;
	while (++i < N)	
	{
		if ((*board)[row_col[i]].size != 1)
			return (0);
	}
	return (1);
}

int	get_num_from_cell(t_cell **board, int cell_index)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	while (++i < N)
	{
		if ((*board)[cell_index].nums[i] != 0)
		{
			num = (*board)[cell_index].nums[i];
			break ;
		}
	}
	return (num);
}

int	*get_sequences(t_cell **board, int *row_col)
{
	int	i;
	int	*sequences;

	i = -1;
	sequences = malloc(sizeof(int) * (N + 1));
	while (++i < N)
		sequences[i] = get_num_from_cell(board, row_col[i]);
	sequences[N] = 0;
	return (sequences);
}

void	sequences_elimination(t_cell **board, int *int_clues)
{
	int	i;
	//remember to free
	int	*cell_indices;
	//remember to free
	int	*sequence;

	i = -1;
	while (++i < 2)
	{
		cell_indices = get_cell_indices_clue_index(i);
		if (!is_in_order(board, cell_indices))
		{
			sequence = get_sequences(board, cell_indices);
			//if (is_right_sequences())
			//
			print_arr(sequence);
		}
	}
}
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