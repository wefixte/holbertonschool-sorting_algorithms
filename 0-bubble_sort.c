#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	int tempo, turn;
	size_t index, index2;

	/* check if array is NULL or size is less than 2 */
	if (array == NULL || size < 2)
		return;

	/* loop through array multiple times */
	for (index = 0; index < size - 1; index++)
	{
		turn = 0;

		/* Loop to compare the elements next to each other */
		for (index2 = 0; index2 < size - index - 1; index2++)
		{
			/* check if current element is greater than next element */
			if (array[index2] > array[index2 + 1])
			{
				/* swap elements */
				tempo = array[index2];
				array[index2] = array[index2 + 1];
				array[index2 + 1] = tempo;

				/* print array */
				turn = 1; /* indicate if change was made */
				print_array(array, size);
			}
		}
		/* check if array is sorted */
		if (turn == 0)
			break;
	}
}
