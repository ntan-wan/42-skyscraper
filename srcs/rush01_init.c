/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:17:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/30 01:10:44 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

void	init_size(t_cell **board, int cell_index)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < TOTAL_COLS)
	{
		if ((*board)[cell_index].nums[i])
			count++;
	}
	(*board)[cell_index].size = count;
}

void	init_board(t_cell **board)
{
	int		i;
	t_cell	new_cell;

	new_cell = (t_cell){.size = 0, .nums = NULL};
	*board = malloc(sizeof(t_cell) * (TOTAL_CELLS));
	if (!board)
		return ;
	i = -1;
	while (++i < TOTAL_CELLS)
		(*board)[i] = new_cell;
}

void	init_values(t_cell **board)
{
	int	i;
	int	j;
	int	*possible_nums;

	i = -1;
	while (++i < TOTAL_CELLS)
	{
		j = -1;
		possible_nums = malloc(sizeof(int) * (N + 1));
		possible_nums[N] = 0;
		while (++j < TOTAL_COLS)
			possible_nums[j] = j + 1;
		(*board)[i].nums = possible_nums;
		init_size(board, i);
	}
}
