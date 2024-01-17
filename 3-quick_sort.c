#include "sort.h"

/**
 * lomuto - partitions the array
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 * Return: index of pivot
*/

size_t lomuto(int *array, int low, int high, size_t size)
{

	int index, index2, pivot, temp;

	index = low - 1;
	pivot = array[high];

	for (index2 = low; index2 <= high - 1; index2++)
	{
		if (array[index2] <= pivot)
		{
			index++;
			temp = array[index];
			array[index] = array[index2];
			array[index2] = temp;
			if (index != index2)
				print_array(array, size);
		}
	}
	temp = array[index + 1];
	array[index + 1] = array[high];
	array[high] = temp;
	if (index + 1 != index2)
		print_array(array, size);
	return (index + 1);
}

/**
 * quick_sort_helper - sorts the array
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
*/

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - a quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
