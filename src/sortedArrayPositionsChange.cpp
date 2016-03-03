/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void swap(int *Arr, int p1, int p2)
{
	int temp = Arr[p1];
	Arr[p1] = Arr[p2];
	Arr[p2] = temp;
}

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i,position1=-1, position2=-1;
	if (Arr==NULL || len<=0)
	return NULL;
	else
	{
		for ( i = 0; i < len-1; i++)
		{
			if (Arr[i] > Arr[i + 1])
			{
				position1 = i;
				i++;
				break;
			}
		}
		for (; i < len - 1; i++)
		{
			if (Arr[i] > Arr[i + 1])
			{
				position2 = i + 1;
				break;
			}
		}
		
		if (position1 != -1 && position2 != 1)
		{
			swap(Arr, position1, position2);
		}

	}
}