/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

void Path_Recursion(int *a, int i, int j, int end_i, int end_j, int last_i, int last_j, int rows, int columns, int flagi, int flagj, int *res);

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows < 0 || columns < 0 || x1 < 0 || x1 >= rows || x2 < 0 || x2 >= rows || y1 < 0 || y1 >= columns || y2 < 0 || y2 >= columns)	//invalid size
	{
		return 0;
	}

	if (maze[(x1*columns) + y1] == 0 || maze[(x2*columns) + y2] == 0)
	{
		return 0;
	}

	int res;
	Path_Recursion(maze, x1, y1, x2, y2, -1, -1, rows, columns, 0, 0, &res);
	return res;
}

void Path_Recursion(int *a, int i, int j, int end_i, int end_j, int last_i, int last_j, int rows, int columns, int flagi, int flagj, int *res)
{
	int present_i = i;
	int present_j = j;
	if (i == end_i && j == end_j)
	{
		*res = 1;	return;
	}
	if (flagi == 1)
	{
		flagi = 0;
		if ((j + 1) >= columns || (j + 1) < columns && a[(i*columns) + (j + 1)] == 0)
		{
			if ((i - 1) < 0 || (i - 1) >= 0 && a[((i - 1)*columns) + j] == 0)
			{
				if ((j - 1) < 0 || (j - 1) >= 0 && a[(i * columns) + (j - 1)] == 0)
				{
					i++;
				}
				else{ j--;  flagj = 1; }
			}
			else{ i--;  flagi = 1; }
		}
		else{ j++; }
	}
	else if (flagj == 1)
	{
		flagj = 0;
		if ((i + 1) >= rows || (i + 1) < rows && a[((i + 1)*columns) + j] == 0)
		{
			if ((i - 1) < 0 || (i - 1) >= 0 && a[((i - 1)*columns) + j] == 0)
			{
				if ((j - 1) < 0 || (j - 1) >= 0 && a[(i*columns) + (j - 1)] == 0)
				{
					j++;
				}
				else{ j--;  flagj = 1; }
			}
			else{ i--;  flagi = 1; }
		}
		else{ i++; }
	}
	else if (flagi == 0 && flagj == 0)
	{
		if ((i + 1) >= rows || (i + 1) < rows && a[((i + 1)*columns) + j] == 0)
		{
			if ((j + 1) >= columns || (j + 1) < columns && a[(i*columns) + (j + 1)] == 0)
			{
				if ((i - 1) < 0 || (i - 1) >= 0 && a[((i - 1)*columns) + j] == 0)
				{
					if ((j - 1) < 0 || (j - 1) >= 0 && a[(i*columns) + (j - 1)] == 0)
					{
						*res = 0;	return;
					}
					else{ j--;  flagj = 1; }
				}
				else{ i--;  flagi = 1; }
			}
			else{ j++; }
		}
		else{ i++; }
	}
	if (i == last_i && j == last_j)
	{
		a[(present_i*columns) + present_j] = 0;
	}
	Path_Recursion(a, i, j, end_i, end_j, present_i, present_j, rows, columns, flagi, flagj, res);
}