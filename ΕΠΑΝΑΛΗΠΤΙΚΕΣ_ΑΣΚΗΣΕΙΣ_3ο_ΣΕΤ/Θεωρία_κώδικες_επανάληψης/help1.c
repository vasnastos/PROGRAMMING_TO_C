#include <stdio.h>
#include <string.h>

int main()
{
    char key[100];
    char key1[100];
    //x="vasilis"-->strlen(x)==7 \0
    //Διάβασμα αλφαριθμητικού
    printf("Give string:");
    gets(key);

    //strlen()-->εμφανίζει το μήκος του αλφαριθμητικού
    //strcmp(x1,x2)-->Συγκρίνει το αλφαριθμητικό x1 με το αλφαριθμητικό x2 αλφαβητικά
    //Αν το x1 είναι μεγαλύτερο αλφαβητικά από το x2 η strcmp επιστρέφει τιμή >0
    //Αν το x2 είναι μεγαλύτερο αλφαβητικά από το x1 η strcmp επιστρέφει τιμή <0
    //Αν τα 2 αλφαριθμητικά είναι ίσα η συνάρτηση εεπιστρέφει 0.
     
    printf("Give string:");
    gets(key1);

    if(strcmp(key,key1)>0)
    {
        printf("%s\n",key);
    } 
    else if(strcmp(key,key1)<0)
    {

        /*if(strcmp(key,key1)<0)
        {
            printf("%s\n",key1);
        }
        else
        {
            printf("Equal strings\n");
        }*/       
    }
    else //if(strcmp(key,key1)==0)
    {
        printf("Equal strings\n");
    }
    
    
    if(strcmp(key,key1)==0)

    char copychar[100];
    strcpy(copychar,key);
    //Αντιγράφει το αλφαριθμητικό key στο αλφαριθμητικό copychar.

    //[0-9] ψηφία
    //[Α-Ζ] [a-z]-->Letters γράμματα
    //!@#$%^&*()
    
}