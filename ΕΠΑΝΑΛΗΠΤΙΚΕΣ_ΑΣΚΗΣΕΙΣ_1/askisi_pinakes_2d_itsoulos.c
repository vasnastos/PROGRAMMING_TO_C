#include <stdio.h>
#define LESSONS 3
#define STUDENTS 3

int main()
{
	double lab[STUDENTS][LESSONS];
	double lecture[STUDENTS][LESSONS];
	double finalGrade[STUDENTS][LESSONS] = {0.0};
	int i;
	int countPassed[LESSONS] = {0};
	/** o bathmos mathimatos einai 70% apo tin dialexi kai 30% apo to ergastirio **/
	for (i = 0; i < STUDENTS; i++)
	{
		printf("dwste vathmo gia %d foititi::\n", i + 1);
		for (int j= 0; j< LESSONS; j++)
		{
			printf("Dose bathmo stin dialexi %d mathimatos:", j + 1);
			scanf("%lf", &lecture[i][j]);
			printf("Dose bathmo sto ergastirio %d mathimatos:", j + 1);
			scanf("%lf", &lab[i]);
		}
		printf("\n");
	}
	for (i = 0; i < STUDENTS; i++)
	{
		for (int j = 0; j < LESSONS; j++)
		{
			if (lecture[i][j] >= 5.0 && lab[i][j] >= 5.0)
				countPassed[j]++;
		}
	}

	for (i = 0; i < STUDENTS; i++)
	{
		for (int j = 0; j< LESSONS; j++)
		{
			if (lecture[i][j] >= 5.0 && lab[i][j] >= 5.0)
				finalGrade[i][j] = 0.7 * lecture[i][j] + 0.3 * lab[i][j];
		}
	}

	for (int i = 0; i < LESSONS; i++)
	{
		printf("OI mathites pou perasan to mathima_%d einai %d \n", i+1, countPassed[i]);
	}

	for (int j = 0; j < LESSONS; j++)
	{
		printf("telikoi vathmoi gia mathima %d::\n",j+1);
		for (i = 0; i < STUDENTS; i++)
		{
			printf("TELIKOS BATHMOS foititi_%d=%6.2lf\n", i+1, finalGrade[i][j]);
		}
	}
	return 0;
}
