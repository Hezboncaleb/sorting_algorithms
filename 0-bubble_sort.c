#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n, new_n;
	int tmp;

	if (array == NULL || size < 2)
		return;

	n = size;
	for (i = 0; i < size; i++)
	{
		new_n = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				new_n = i + 1;
				print_array(array, size);
			}
		}
		n = new_n;
	}
}
