#!/usr/bin/python3
"""
    Island Perimeter
"""


def island_perimeter(grid):
    """
        returns the perimeter of the island
        grid is a list of list of integers:
            0 represents a water zone
            1 represents a land zone
            One cell is a square with side length 1
            Grid cells are connected horizontally/vertically (not diagonally).
            Grid is rectangular, width and height don’t exceed 100
    """
    perimeter = 0
    for row in range(0, len(grid), 1):
        for col in range(0, len(grid[0]), 1):
            if grid[row][col] == 1:
                perimeter = perimeter + 4
                if col - 1 >= 0 and grid[row][col - 1] == 1:
                    perimeter -= 2
                if row - 1 >= 0 and grid[row - 1][col] == 1:
                    perimeter -= 2
    return perimeter
