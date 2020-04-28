#include <stdio.h>
#include <string.h>
void reverse_string(char s[],int x,int j)//Αντιστροφή αποτελεσμάτων ώστε να πάρουμε τους σωστούς αριθμούς σε 8-δικό και δεκαεξαδικό(εισάγωνται με αντίστροφη σειρά στον Πίνακα)
{
    int size=strlen(s);//Πέρασμα σε μεταβλητή ώστε να κληθεί μία φορα η συνάρτηση strlen()
    for(int i=0;i<size/2;i++)
    {
        char temp=s[size-i-1];//Αντιστροφή
        char temp2=s[i];//>>
        s[i]=temp;//>>
        s[size-i-1]=temp2;//>>
    }
    if(j==1)//j για έλεγχο επιλογής συστήματος 8-δικό η 16-δικο
     printf("Number %d(10)=>%s(8)\n",x,s);
    else
    printf("Number %d(10)=>%s(16)\n",x,s);
}

void convertt08bit(int y)
{
    //Κώδικας μετατροπής στο 8-δικό
    char k[20];
    int i=0;
    int t=y;//χρήση της t γιατί η y θα μηδενιστεί άρα με την t κρατάω τον αριθμό
    while(y!=0)
    {
        int l=y%8;//Ακέραιο υπόλοιπο διαίρεσης με 8
        k[i]=l+'0';
        y=y/8;
        i++;
    }
    reverse_string(k,t,1);
}

void convertt016bit(int b)
{
    int t=b;
    char k[20];
    int i=0;
    while(b!=0)
    {
        int l=b%16;//Υπόλοιπο διαίρεσης αριθμού με 16
        b/=16;//Ακέραια διαίρεση αριθμού με 16
        switch(l)// έλεγχος σε περίπτωση που το υπόλοιπο έιναι μεγαλύτερο του 9
        {
            case 10:
             k[i]='A';
             break;
            case 11:
              k[i]='B';
              break;
            case 12:
              k[i]='C';
              break;
            case 13:
              k[i]='D';
              break;
            case 14:
              k[i]='E';
              break;
            case 15:
              k[i]='F';
              break;
            default:
              k[i]=l+'0';
              break;
        }
        i++;
    }
    reverse_string(k,t,2);
}

void menu(int x)
{
    //μενού επιλογών
    int ch;
    do {
    printf("Give system you want to convert:");
    scanf("%d",&ch);
    }while(ch!=1 && ch!=2);
    switch(ch)//περιπτώσης μετατροπής 
    {
        case 1:
          convertt08bit(x);
          break;
        case 2: 
          convertt016bit(x);
          break;
    }
}
int main()
{
    menu(64);
    menu(168);
    return 0;
}