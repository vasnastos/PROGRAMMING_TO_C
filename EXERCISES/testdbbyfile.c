#include <stdio.h>
#include <stdlib.h>
#include <cstring>

char filename[100];

typedef struct
{
	int empid;
	char fullname[100];
	double balance;
}employee;

int getsize()
{
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return 0;
	}
	int counter = 0;
	char line[100];
	while (fgets(line, 100, fp) != NULL)
	{
		counter++;
	}
	fclose(fp);
	return counter;
}

void loaddata(employee* emps)
{
	char line[100];
	int i = 0;
	FILE* fp = fopen(filename,"r");
	while (fgets(line, 100, fp) != NULL)
	{
		if (line[0] == '#') continue;
		if(line[0]=='\n') continue;
		if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = '\0';
		char* token = strtok(line, "-");
		emps[i].empid = atoi(token);
		token = strtok(NULL, "-");
		strcpy(emps[i].fullname, token);
		token = strtok(NULL,"-");
		i++;
	}
	fclose(fp);
}

void update_demo_db(employee* emps, int size,int upid,double upbl)
{
	int pos = -1;
	for (int i = 0; i < size; i++)
	{
		if (emps[i].empid == upid)
		{
			pos = i;
		}
	}
	if (pos == -1)
	{
		printf("employee with this id did not found!!!\n");
		return;
	}
	emps[pos].balance = upbl;

	FILE* fp = fopen(filename, "w");
	for (int i = 0; i < size; i++)
	{
		fprintf(fp, "%d---%s---%.2lf\n", emps[i].empid, emps[i].fullname, emps[i].balance);
	}
	fclose(fp);
}

int delete_by_demo_db(employee* emps, int size, int upid)
{
	int pos = -1;
	for (int i = 0; i < size; i++)
	{
		if (emps[i].empid == upid)
		{
			pos = i;
		}
	}
	if (pos == -1)
	{
		printf("No such employee found in demo file db\n");
		return 0;
	}
	for (int i = 0; i < size-1; i++)
	{
		emps[i] = emps[i + 1];
	}
	FILE* fp = fopen(filename, "w");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(fp, "%d---%s---%.2lf\n", emps[i].empid, emps[i].fullname, emps[i].balance);
	}
	fclose(fp);
	return 1;
}

void display_db(employee* employees, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d---%s---%.2lf\n", employees[i].empid, employees[i].fullname, employees[i].balance);
	}
}

int main()
{
	printf("Give filename:");
	gets(filename);
	int choice;
	employee* employees;
	int size = getsize();
	if (size == 0)
	{
		printf("File does not found!!!\n");
		exit(EXIT_FAILURE);
	}
	printf("DB OPEN HELLO FROM EMPLOYEES DEMO FILE DATABASE\n");

	employees = (employee*)malloc(size * sizeof(employee));

	loaddata(employees);
	int id;
	while (1)
	{
		printf("1-UPDATE SALARY\n");
		printf("2-DELETE EMPLOYEE\n");
		printf("3-DISPLAY EMPLOYEES\n");
		printf("4-QUIT\n");
		printf("CHOOSE ACTION:");
		scanf("%d", &choice);
		if (choice == 1)
		{
			double sal;
			printf("Give employee id:");
			scanf("%d", &id);
			printf("Give updated salary:");
			scanf("%d", &sal);
			update_demo_db(employees, size, id, sal);
		}
		else if (choice == 2)
		{
			printf("Give id:");
			scanf("%d", &id);
			int action = delete_by_demo_db(employees, size, id);
			if (action == 1)
			{
				size--;
				employees = (employee*)realloc(employees,size * sizeof(employee));
			}
		}
		else if (choice == 3)
		{
			display_db(employees, size);
		}
		else
		{
			break;
		}
	}
}