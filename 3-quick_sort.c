#include "sort.h"
#include <stdio.h>

/**
 * partition - finds partition the quicksort using the Lomuto scheme
 * @array: array to sort
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of array
 *
 * Return: partition
 */
int partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int index, j;
	int tmp, pivot;

	pivot = array[high];
	index = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			index++;
			if (index != j)
			{
				tmp = array[index];
				array[index] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[index + 1])
	{
		tmp = array[index + 1];
		array[index + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (index + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @lo: lowest index of partition
 * @hi: highest index of partition
 * @size: size of array
 * Return: nothing
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
