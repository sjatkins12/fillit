#include "header.h"
#include <stdio.h>
#include <time.h>

int	main(void)
{
	int			num_tetriminos;
	t_tetrimino	*t;
	t_tetrimino *start;
	int			j;
	clock_t		start_t;
	clock_t		stop;
	float		time_spent;
	float		shortest;
	float		average;
	float		longest;
	int			num_tests;

	num_tetriminos = 10;
	t = (t_tetrimino *)malloc(sizeof(t_tetrimino) * num_tetriminos);
	if (!t)
		return (0);
	start = t;

	// ft_strcpy(t->grid[0], "....");
	// ft_strcpy(t->grid[1], ".###");
	// ft_strcpy(t->grid[2], "...#");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'A';
	// t->xdim = 3;
	// t->ydim = 2;
	// t->next = NULL;
	// t++;
	for(int i = 0; i < num_tetriminos; i++)
	{
		ft_strcpy(t->grid[0], "....");
		ft_strcpy(t->grid[1], "..##");
		ft_strcpy(t->grid[2], "..##");
		ft_strcpy(t->grid[3], "....");
		// ft_strcpy(t->grid[0], "...#");
		// ft_strcpy(t->grid[1], "...#");
		// ft_strcpy(t->grid[2], "...#");
		// ft_strcpy(t->grid[3], "...#");
		t->num = 'A' + i;
		t->xdim = 2;
		t->ydim = 2;
		t->type = 's';
		t->next = t + 1;
		t++;
	}
	t--;
	t->next = NULL;
	// ft_strcpy(t->grid[0], ".#..");
	// ft_strcpy(t->grid[1], ".##.");
	// ft_strcpy(t->grid[2], ".#..");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'C';
	// t->xdim = 2;
	// t->ydim = 3;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], "....");
	// ft_strcpy(t->grid[1], "###.");
	// ft_strcpy(t->grid[2], ".#..");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'D';
	// t->xdim = 3;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;
	
	// ft_strcpy(t->grid[0], "....");
	// ft_strcpy(t->grid[1], ".###");
	// ft_strcpy(t->grid[2], ".#..");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'E';
	// t->xdim = 3;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], "...#");
	// ft_strcpy(t->grid[1], "...#");
	// ft_strcpy(t->grid[2], "...#");
	// ft_strcpy(t->grid[3], "...#");
	// t->num = 'F';
	// t->type = 'i';
	// t->xdim = 1;
	// t->ydim = 4;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], "....");
	// ft_strcpy(t->grid[1], "..##");
	// ft_strcpy(t->grid[2], ".##.");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'G';
	// t->xdim = 2;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], ".#..");
	// ft_strcpy(t->grid[1], ".###");
	// ft_strcpy(t->grid[2], "....");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'H';
	// t->xdim = 3;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], "####");
	// ft_strcpy(t->grid[1], "....");
	// ft_strcpy(t->grid[2], "....");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'I';
	// t->type = 'i';
	// t->xdim = 4;
	// t->ydim = 1;
	// t->next = NULL;
	// t++;

	// ft_strcpy(t->grid[0], "....");
	// ft_strcpy(t->grid[1], ".###");
	// ft_strcpy(t->grid[2], "...#");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'J';
	// t->xdim = 3;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], "...#");
	// ft_strcpy(t->grid[1], ".###");
	// ft_strcpy(t->grid[2], "....");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'K';
	// t->xdim = 3;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], "....");
	// ft_strcpy(t->grid[1], ".##.");
	// ft_strcpy(t->grid[2], "..##");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'L';
	// t->xdim = 2;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], "..#.");
	// ft_strcpy(t->grid[1], ".###");
	// ft_strcpy(t->grid[2], "....");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'M';
	// t->xdim = 3;
	// t->ydim = 2;
	// t->next = t + 1;
	// t++;

	// ft_strcpy(t->grid[0], ".#..");
	// ft_strcpy(t->grid[1], "##..");
	// ft_strcpy(t->grid[2], ".#..");
	// ft_strcpy(t->grid[3], "....");
	// t->num = 'N';
	// t->xdim = 2;
	// t->ydim = 3;
	// t->next = NULL;
	// t++;


	t = start;
	num_tests = 1;
	j = 0;
	shortest = -1;
	average = 0;
	longest = 0;
	while (j < num_tests)
	{
		start_t = clock();
		ft_place_tetriminos(t);
		stop = clock();
		time_spent = (double)(stop - start_t)/CLOCKS_PER_SEC;
		average += time_spent;
		if (shortest == -1 || shortest > time_spent)
			shortest = time_spent;
		if (time_spent > longest)
			longest = time_spent;
		j++;
	}
	average /= num_tests;
	printf("Testing Metrics:\nNumber of Tetriminos: %d\nNumber of Tests: %d\nShortest time: %f\nLongest time: %f\nAverage time: %f\n", num_tetriminos, num_tests, shortest, longest, average);
	free(start);
}
