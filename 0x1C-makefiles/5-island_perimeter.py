#!/usr/bin/python3
"""function island_perimeter"""


def island_perimeter(grid):
    """calculate island

    grid is a list of list of integers:
    0 reps water zone
    1 reps land zone
    Returns perimeter of the island in grid
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for x in range(height):
        for i in range(width):
            if grid[x][i] == 1:
                size += 1
                if (i > 0 and grid[x][i - 1] == 1):
                    edges += 1
                if (x > 0 and grid[x - 1][i] == 1):
                    edges += 1
    return size * 4 - edges * 2
