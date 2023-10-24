#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array in ascending order
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int swp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swp;
				print_array(array, size);
			}
		}
	}
}
