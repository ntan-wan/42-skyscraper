/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:21:51 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/29 11:15:04 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define N 4
# define TOTAL_ROWS N 
# define TOTAL_COLS N 
# define TOTAL_CELLS N * N

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_cell
{
	int	nums[N];
	int	size;
	int	cell_index;
} t_cell;

/* edge */
void	edge_clues(t_cell **board, int *int_clues);

/* constraint */
void	propagate_constraint(t_cell **board);

/* eliminate */
void	process_elimination(t_cell **board);

/* init */
void	init_board(t_cell **board);
void	init_values(t_cell **board);
void	init_size(t_cell **board, int cell_index);

/* get */
int		*get_cell_indices_row_index(int row_index);
int		*get_cell_indices_col_index(int col_index);
int		*get_cell_indices_clue_index(int clue_index);

/* utils */
size_t	utils_strlen(const char *str);
void	utils_putstr_fd(char *c, int fd);
void	util_print_board(t_cell **board);
int		duplicate_check(t_cell **board, int cell_index, int *row_col, int num);

/* ft */
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
char	**ft_split(char const *s, char c);

/* cell */
void	remove_all_left_one(t_cell **board, int cell_index, int num);
int		remove_duplicated_num(t_cell **board, int cell_index, int *row_col, int num);

void	print_arr(int *arr);
#endif