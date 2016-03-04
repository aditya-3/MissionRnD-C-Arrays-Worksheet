/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void swap(struct student *students, int p1, int p2)
{
	int temp = students[p1].score;
	students[p1].score = students[p2].score;
	students[p2].score = temp;
}
void sort(struct student *students, int len) {
	for (int i = 0; i < len - 1; i++) //bubble sort
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (students[j].score > students[j + 1].score)
				swap(students, j, j + 1);
		}
	}
}
struct student ** topKStudents(struct student *students, int len, int K) {
	struct student ** top_k ;
	int j = 0;
	
	if (len <= 0 || K <= 0)
		return NULL;
	else
		sort(students, len);

	if (K == 1 ){
		top_k = (struct student**)malloc(sizeof(struct student)*1);
		top_k[j++] = &students[len - 1];
     }
	else 
	{
		if (K > len)
			K = len;
		 top_k = (struct student**)malloc(sizeof(struct student)*K);
		 for (int i = len - K; i < len; i++)
				top_k[j++] = &students[i];
	}
	return top_k;
	
}