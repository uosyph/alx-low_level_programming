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
    if not grid:
        return

    land = 0
    edge = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                land += 1
                if x > 0 and grid[x-1][y] == 1:
                    edge += 1
                if y > 0 and grid[x][y-1] == 1:
                    edge += 1
    return land * 4 - edge * 2
