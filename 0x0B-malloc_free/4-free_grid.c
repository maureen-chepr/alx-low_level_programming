#include "main.h"
#include <stdlib.h>

/**
 * free_grid - function that frees a 2 dimensional grid previously
 * created by your alloc_grid function
 * @grid: address of 2D array
 * @height: elements of the row
 */
void free_grid(int **grid, int height)
{
	int x;

	if (grid == NULL || height <= 0)
	{
		return;
	}
	for (x = 0; x < height; x++)
	{
		free(grid[x]);
	}
	free(grid);
}
