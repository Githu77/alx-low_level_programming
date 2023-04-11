#include "main.h"
/**
*free_grid - frees the memory of a grid(2d array)
*@grid: the grid to free
*@height: height of array
*Return: returns nothing
*
*
*
*/
void free_grid(int **grid, int height)
{
	int x;

	if (grid != NULL)
	{
		for (x = 0; x < height; x++)
		{
			free(grid[x]);
		}
		free(grid);
	}
}
