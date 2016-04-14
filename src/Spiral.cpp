/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void spiral_recursion(int r, int c, int **input_array, int *a, int rows, int columns, int index);

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;

	int *arr = (int *)malloc(sizeof(int)*(rows * columns));
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(arr + k) = (int)*(*(input_array + i) + j);	k++;
		}
	}
	spiral_recursion(0, columns, input_array, (arr + columns), rows, columns, 0);
	return arr;
}

void spiral_recursion(int r, int c, int **input_array, int *a, int rows, int columns, int index)
{
	if (index == (rows * columns) - rows)
		return;

	for (int i = c; i < columns - c; ++i)
	{
		*(a + index) = (int)*(*(input_array + r) + i);
		index++;
	}
	if (c == columns)
	{
		c = c + (columns - 1 - c);
	}
	else
	{
		c = (columns - 1 - c);
	}

	if (index < (rows * columns) - rows)
	{
		for (int i = r + 1; i < rows - r; ++i)
		{
			*(a + index) = (int)*(*(input_array + i) + c);
			index++;
		}
		r = (rows - 1 - r);
	}
	else
	{
		return;
	}

	if (index < (rows * columns) - rows)
	{
		for (int i = c - 1; i >= columns - 1 - c; --i)
		{
			*(a + index) = (int)*(*(input_array + r) + i);
			index++;
		}
		c = columns - 1 - c;
	}
	else
		return;

	if (index < (rows * columns) - rows)
	{
		for (int i = r - 1; i > rows - 1 - r; --i)
		{
			*(a + index) = (int)*(*(input_array + i) + c);
			index++;
		}
		r = rows - r;
	}
	else
		return;

	spiral_recursion(r, ++c, input_array, a, rows, columns, index);
}