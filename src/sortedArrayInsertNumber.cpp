/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 0)
		return NULL;
	else if (len == 0)
	{	
		Arr = (int *)realloc(Arr, sizeof(int)*(len + 1));
		Arr[0] = num;
		return Arr;
	}
	else if (len == 1)
	{
		Arr = (int *)realloc(Arr, sizeof(int)*(len + 1));
		if (Arr[0]>num)
		{
			Arr[1] = Arr[0];
			Arr[0] = num;
		}
		else
			Arr[1] = num;
	}
	else
	{
		Arr = (int *)realloc(Arr, sizeof(int)*(len + 1));
		int i = 0,position=0;
		while (num > Arr[i] && i<len)
			i++;
		position = i;
		if (position == len)
			Arr[len] = num;
		else
		{
			for (i = len; i > position; i--)
				Arr[i] = Arr[i - 1];
			Arr[position] = num;
		}
		return Arr;
	}
}