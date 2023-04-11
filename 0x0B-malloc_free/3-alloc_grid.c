#include "main.h"
/**
*alloc_grid - points to a 2d array
*@width: width of array
*@height: height of array
*Return: returns either NULL or pointe of array
*
*
*
*/
int **alloc_grid(int width, int height)
{
	int **grid, i, j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = (int **) malloc(sizeof(int *) * height);

	if (grid != NULL)
	{
		for (i = 0; i < height; i++)
		{
			grid[i] = (int *)malloc(sizeof(int) * width);
			if (grid[i] != NULL)
			{
				for (j = 0; j < width; j++)
				{
					free(grid[j]);
				}
				free(grid);
				return (NULL);
			}
			for (j = 0; j < width; j++)
			{
				grid[i][j] = 0;
			}
		}
	}
	return (grid);
}
