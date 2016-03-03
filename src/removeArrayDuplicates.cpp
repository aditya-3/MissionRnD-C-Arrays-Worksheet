/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int removeArrayDuplicates(int *Arr, int len)
{
	int sortFlag = 0;
	if (Arr == NULL || len <= 0)
		return -1;
	else if (len == 1 || (len == 2 && Arr[0] == Arr[1]))
	{
		return 1;
	}
	else if (len == 2)
		return 2;
	else
	{
		for (int i = 0; i < len-1;i++)//checking for already sorted array
		{
			if (Arr[i] <= Arr[i + 1])
				continue;
			else
			{
				sortFlag = 1;
				break;
			}
		}
		if (sortFlag == 1)
		{
			for (int i = 0; i < len - 1; i++) //bubble sort
			{
				for (int j = 0; j < len - i - 1; j++)
				{
					if (Arr[j] > Arr[j + 1])
						swap(&Arr[j], &Arr[j + 1]);
				}
			}
			
		}
		
		int j = 0;
		for (int i = 0; i < len - 1; i++)//removing duplicates
		{
			if (Arr[i] == Arr[i + 1])
				continue;
			else
				Arr[j++] = Arr[i];
		}
		if (Arr[j - 1] != Arr[len - 1])
			Arr[j++] = Arr[len - 1];
		return j;
	}

}