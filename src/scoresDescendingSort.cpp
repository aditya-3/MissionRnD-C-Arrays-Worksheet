/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
void swaping(struct student *students,int p1,int p2)
{
	int temp = students[p1].score;
	students[p1].score = students[p2].score;
	students[p2].score = temp;
}
void sorting(struct student *students, int len) {
	for (int i = 0; i < len - 1; i++) //bubble sort
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (students[j].score < students[j + 1].score)
				swaping(students, j, j + 1);
		}
	}
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len <= 0)
		return NULL;
	else if (len == 2)
	{
		if (students[0].score < students[1].score)
			swaping(students,0, 1);
	}
	else
	{
		sorting(students, len);
	}

}