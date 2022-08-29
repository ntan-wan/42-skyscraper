/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:01:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/30 01:38:51 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"


void	print_arr(int *arr)
{
	int		i;;
	char	*c;

	if (!arr)
		return ;
	i = -1;
	while (++i < N)
	{
		c = ft_itoa(arr[i]);
		utils_putstr_fd(c, 1);
		utils_putstr_fd("|", 1);
	}
	write(1, "\n", 1);
	free(c);
}

static int	*atoi_clues(char **splitted_clues)
{
	int	i;
	int	*int_clues;

	int_clues = malloc(sizeof(int) * (TOTAL_CELLS + 1));
	i = -1;
	while (splitted_clues[++i])
		int_clues[i] = ft_atoi(splitted_clues[i]);
	int_clues[TOTAL_CELLS] = 0;
	return (int_clues);
}

int	main(int ac, char **av)
{
	int		*int_clues;
	char	**splitted_clues;
	t_cell	*board;
	
	//check input ...
	(void)ac;
	splitted_clues = ft_split(av[1], ' ');
	int_clues = atoi_clues(splitted_clues);
	init_board(&board);
	init_values(&board);
	edge_clues(&board, int_clues);
	propagate_constraint(&board);
	process_elimination(&board);
	sequences_elimination(&board, int_clues);
	utils_print_board(&board);
	utils_free_all(&board, &splitted_clues, &int_clues);
	return (0);
}