/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:17:18 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/28 22:26:18 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

void	init_board(t_cell **board)
{
	int		i;
	int		j;
	t_cell	new_cell;

	*board = malloc(sizeof(t_cell) * (TOTAL_CELLS + 1));
	if (!board)
		return ;
	(*board)[TOTAL_CELLS].nums[0] = 0;
	i = -1;
	while (++i < TOTAL_CELLS)
		(*board)[i] = new_cell;
}

void	init_values(t_cell **board)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TOTAL_CELLS)
	{
		j = -1;
		while (++j < TOTAL_COLS)
			(*board)[i].nums[j] = j + 1;
	}
}
