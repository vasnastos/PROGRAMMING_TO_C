#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define r 4
#define n 10
#define p 20

void boot(int r1[], int r2[], int ad[][r])
{
	for (int i = 0; i < r; i++)
	{
		r1[i] =0;
		r2[i]=0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < r; j++)
		{
			ad[i][j] = rand()%2;
		}
	}
}

int loadR1(int AD[][r],int r1[],int address)
{
	if (address >= 0 && address <= 9)
    {
		for(int i=0;i<r;i++)
		{
           r1[i]=AD[address][i];
		}
		return 1;
	}
	return 0;
}

int loadR2(int AD[][r],int r2[],int address)
{
	if (address >= 0 && address <= 9)
    {
		for(int i=0;i<r;i++)
		{
           r2[i]=AD[address][i];
		}
		return 1;
	}
	return 0;
}

int storeR1(int AD[][r], int r1[], int address)
{
	for (int i = 0; i < n; i++)
	{
		if (i == address)
		{
			for (int j = 0; j < r; j++)
			{
				AD[i][j] = r1[j];
			}
			return 1;
		}
	}
	return 0;
}

int storeR2(int AD[][r], int r2[], int address)
{
	for (int i = 0; i < n; i++)
	{
		if (i == address)
		{
			for (int j = 0; j < r; j++)
			{
				AD[i][j] = r2[j];
			}
			return 1;
		}
	}
    return 0;
}

void addRegistersR1(int r1[], int r2[])
{
	int dec1 = 0;
	int dec2 = 0;
	int j = 8;
	int s = 0;
	for (int i = 0; i < r; i++)
	{
		dec1 += j * r1[i];
		dec2 += j * r2[i];
		j /= 2;
	}
	s = dec1 + dec2;
	if (s > 15)
	{
		for (int i = 0; i < r; i++)
		{
			r1[i] = 0;
		}
	}
	else
	{
		for(int j=r-1;j>=0;j--)
		{
			r1[j] = s % 2;
			s /= 2;
			j--;
		}
	}
}

void addRegistersR2(int r1[], int r2[])
{
	int dec1 = 0;
	int dec2 = 0;
	int j = 8;
	int s = 0;
	for (int i = 0; i < r; i++)
	{
		dec1 += j * r1[i];
		dec2 += j * r2[i];
		j /= 2;
	}
	s = dec1 + dec2;
	if (s > 15)
	{
		for (int i = 0; i < r; i++)
		{
			r2[i] = 0;
		}
	}
	else
	{
		int j = 3;
		for(int j=r-1;j>=0;j--)
		{
			r2[j] = s % 2;
			s /= 2;
		}
	}
}

void subRegistersR1(int r1[], int r2[])
{
	int dec1 = 0;
	int dec2 = 0;
	int j = 8;
	int s = 0;
	for (int i = 0; i < r; i++)
	{
		dec1 += j * r1[i];
		dec2 += j * r2[i];
		j /= 2;
	}
	s = dec1 - dec2;
	if (s < 0)
	{
		for (int i = 0; i < r; i++)
		{
			r1[i] = 1;
		}
	}
	else
	{
		int j = 3;
		for(int j=r-1;j>=0;j--)
		{
			r1[j] = s % 2;
			s /= 2;
		}
	}
}

void subRegistersR2(int r1[], int r2[])
{
	int dec1 = 0;
	int dec2 = 0;
	int j = 8;
	int s = 0;
	for (int i = 0; i < r; i++)
	{
		dec1 += j * r1[i];
		dec2 += j * r2[i];
		j /= 2;
	}
	s = dec2 - dec1;
	if (s < 0)
	{
		for (int i = 0; i < r; i++)
		{
			r2[i] = 1;
		}
	}
	else
	{
		int j = 3;
		for(int j=r-1;j>=0;j--)
		{
			r2[j] = s % 2;
			s /= 2;
		}
	}
}

void displayR1(int r1[])
{
	printf("[");
	for (int i = 0; i < r; i++)
	{
		if (i < r - 1)
			printf("%d,", r1[i]);
		else
		{
			printf("%d", r1[i]);
		}
	}
	printf("]\n");
}
void displayR2(int r2[])
{
	printf("[");
	for (int i = 0; i < r; i++)
	{
		if (i < r - 1)
			printf("%d,", r2[i]);
		else
		{
			printf("%d", r2[i]);
		}
	}
	printf("]\n");
}

void displayMemory(int ad[][r])
{
	for (int i = 0; i < n; i++)
	{
		printf("Memory Address %d : [", i);
		for (int j = 0; j < r; j++)
		{
			if (j < r - 1)
				printf("%d,", ad[i][j]);
			else
			{
				printf("%d", ad[i][j]);
			}
		}
		printf("]\n");
	}
}
void printcommands()
{
	printf("- BOOT \n");
	printf("- LOAD R N \n");
	printf("- STORE R N \n");
	printf("- ADD R \n");
	printf("- SUB R \n");
	printf("- SHOW R \n");
	printf("- MEM \n");
}

void split_string(char c[], char w1[], char w2[], char w3[])
{
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int empty = 0;
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] == ' ')
		{
			empty++;
		}
		else if (c[i] != ' ' && empty == 0)
		{
			w1[cnt1++] = c[i];
		}
		else if (c[i] != ' ' && empty == 1)
		{
			w2[cnt2++] = c[i];
		}
		else
		{
			w3[cnt3++] = c[i];
		}
	}
	w1[cnt1] = '\0';
	w2[cnt2] = '\0';
	w3[cnt3] = '\0';
}

int main()
{
	int ADDRESS[n][r];
	int R1[r];
	int R2[r];
	char cmd[p];
	char word1[p];
	char word2[p];
	char word3[p];

	while (1)
	{
		printf("Welcome to MCU :: \n");
		printf("Give command for execution (PRESS /help for available commands): \n");
		gets(cmd);
		split_string(cmd, word1, word2, word3);
	/*	//	printf("Command is = %s \n",word1);
		//	printf("To Register = %s \n",word2);
		//	printf("At Position = %s \n",word3);
	
		if ((strcmp(word2," ")==0) && (strcmp(word3," ")==0))
		{
			printf("Command is = %s \n", word1);
		}
		else if (strcmp(word3," ")==0)
		{
			printf("Command is = %s \n",word1);
			printf("To Register = %s \n",word2);
		}
		else 
		{
			printf("Command is = %s \n",word1);
			printf("To Register = %s \n",word2);
			printf("At Position = %s \n",word3);
		}*/
		
		if (strcmp(word1,"/help")==0)
		{
			printf("Command is = %s \n",word1);
			printcommands();
		}
		else if (strcmp(word1,"BOOT")==0)
		{
			printf("Command is = %s \n",word1);
			boot(R1,R2,ADDRESS);
		}
		else if (strcmp(word1, "LOAD")==0)
		{
			printf("Command is = %s \n",word1);
			printf("To Register = %s \n",word2);
			printf("At Position = %s \n",word3);
			
			int x=10;
			if(strlen(word3)==1)
			{
				x=word3[0]-'0';
			}
			if (strcmp(word2,"R1")==0)
			{
				int res = loadR1(ADDRESS,R1,x);
				if (res == 0)
				{
					perror("WRONG memory input !!!");
				}
				else
				{
					printf("Load to Register R1 was SUCCESFUL ! \n");
				}
			}
			else if (strcmp(word2,"R2")==0 )
			{
				int res = loadR2(ADDRESS,R2,x);
				if (res == 0)
				{
					perror("WRONG memory input !!! ");
				}
				else
				{
					printf("Load to Register R2 was SUCCESFUL !\n");
				}
			}
			else
			{
				perror("NO SUCH REGISTER EXISTS IN MCU !!!");
			}
		}
		else if (strcmp(word1, "STORE")==0)
		{
			printf("Command is = %s \n",word1);
			printf("To Register = %s \n",word2);
			printf("At Position = %s \n",word3);
	
			int x = 10;
			if(strlen(word3)==1) 
			{
				x=word3[0]-'0';
			}
			if (strcmp(word2,"R1"))
			{
				int res = storeR1(ADDRESS, R1, x);
				if (res == 0)
				{
					perror("WRONG memory input !!! ");
				}
				else
				{
					printf("Store to memory address of Register R1 was SUCCESFUL !\n");
				}
			}
			else if (strcmp(word2,"R2"))
			{
				int res = storeR2(ADDRESS, R2, x);
				if (res == 0)
				{
					perror("WRONG memory input !!!");
				}
				else
				{
					printf("Store to memory address of Register R2 was SUCCESFUL !\n");
				}
			}
			else
			{
				perror("NO SUCH REGISTER EXISTS IN MCU !!!");
			}
		}
		else if (strcmp(word1, "ADD")==0)
		{
			printf("Command is = %s \n",word1);
			printf("To Register = %s \n",word2);
			
			if (strcmp(word2,"R1")==0)
			{
				addRegistersR1(R1, R2);
				printf("Add to Register R1 was SUCCESSFULL ! \n");
			}
			else if (strcmp(word2,"R2")==0)
			{
				addRegistersR2(R1, R2);
				printf("Add to register R2 was SUCCESSFULL ! \n");
			}
			else
			{
				perror("NO SUCH REGISTER EXISTS IN MCU !!! ");
			}	
		}
		else if (strcmp(word1, "SUB")==0)
		{
			printf("Command is = %s \n",word1);
			printf("To Register = %s \n",word2);
		
			if (strcmp(word2,"R1")==0)
			{
				subRegistersR1(R1, R2);
				printf("Sub to Register R1 was SUCCESSFUL ! \n");
			}
			else if (strcmp(word2,"R2")==0)
			{
				subRegistersR2(R1, R2);
				printf("Sub to Register R2 was SUCCESSFUL ! \n");
			}
			else
			{
				perror("NO SUCH REGISTER EXISTS IN MCU !!! ");
			}
		}
		else if (strcmp(word1, "SHOW")==0)
		{
			printf("Command is = %s \n",word1);
			printf("To Register = %s \n",word2);
		
			if (strcmp(word2, "R1")==0)
			{
				displayR1(R1);
			}
			else if (strcmp(word2, "R2")==0)
			{
				displayR2(R2);
			}
			else
			{
				perror("NO SUCH REGISTER EXISTS IN MCU !!! ");
			}
		}
		else if (strcmp(word1,"MEM")==0)
		{
			printf("Command is = %s \n",word1);
			displayMemory(ADDRESS);
		}
		else
		{
			perror("NO SUCH COMMAND WAS ABLE TO EXECUTE FROM MICROCOMPUTER !!! \n");
		}
	}
	return 0;
}
