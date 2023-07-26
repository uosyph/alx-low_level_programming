#!/usr/bin/python3
"""Calculates the perimeter of the island of a grid."""


def island_perimeter(grid):
    """Calculates the perimeter of the island of a grid.
    The grid is a matrix of integers:
        0 represents a water zone.
        1 represents a land zone.
        One cell is a square with side length 1.
        Grid cells are connected horizontally/vertically (not diagonally).
        Grid is rectangular, width and height don't exceed 100.
    Grid is completely surrounded by water,
    and there is one island (or nothing).
    The island doesn't have "lakes"
    (water inside that isn't connected to the water around the island).
    """
    count = 0
    touches = 0
    height = 0
    width = 0

    if grid:
        for row in grid:
            height += 1
        width = len(grid[0])
        for x in range(height):
            for y in range(width):
                if grid[x][y] == 1:
                    count += 1
                    if y - 1 >= 0:
                        if grid[x][y - 1] == 1:
                            touches += 1
                    if y + 1 < width:
                        if grid[x][y + 1] == 1:
                            touches += 1
                    if x + 1 < height:
                        if grid[x + 1][y] == 1:
                            touches += 1
                    if x - 1 >= 0:
                        if grid[x - 1][y] == 1:
                            touches += 1
        count = count * 4 - touches
        return count
