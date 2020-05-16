//1.
//struct -->βιβλια
//Δεδομένα τίτλος,συγγραφέα,τιμή
//main()-->να φτιαχτεί πίνακαςγια 5 βιβλία εισαγωγή τιμών απο των χρήστη
//typedef struct  
//2.Να φτιαχτεί συνάρτηση η οποία θα υπολογιζει το βιβλίο με την χαμηλότερη τιμή
//και θα το εμφανίζει
#include<stdio.h>

typedef struct
{
	char title[100];
	char author[100];
	double price;	
}book;

void find_min (book *books,int size)
{
	book min=books[0];
	for(int i=0;i<size;i++)
	{
		if(books[i].price<min.price)
		{
			min=books[i];
		}
	}
	printf("%s %s %lf",min.title,min.author,min.price);
}


int main()
{
	book b[5];
	for(int i=0;i<5;i++)
	{
		fflush(stdin);
		printf("Give title:");
		gets(b[i].title);
		printf("Give author:");
		gets(b[i].author);
		printf("Give ")
		scanf("%lf",&b[i].price);
	}
	find_min(b,5);
    return 0;
}
