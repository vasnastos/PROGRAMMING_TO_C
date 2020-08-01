#include <stdio.h>
#include <stdlib.h>
typedef struct 
{ 
  //to be implement
}book;
void find_books_of_author(book *books,int size,char *auth)
{
   //to be implement
}
void delete_at_pos(book *books,int size,char *title)
{
   //to be implement
}
void save_to_file(book *books,int size)
{
   //to be implement
}
double average_price(book *books,int)
{
    //to be implement
}
void find_expensive_book(book *books,int size)
{
   //to be implement
}
int main()
{
    int size;
    book *books;
    //
    //
    int choice;
    char book_title[maxsize];
    char author_name[maxsize];
    while(1)
    {
        printf("1-SEARCH AUTHOR BOOKS\n");
        printf("2-DELETE BOOK\n");
        printf("3-FIND EXPENSIVE BOOK\n");
        printf("4-AVERAGE PRICE\n");
        printf("5-SAVE TO FILE\n");
        printf("6-EXIT MENU\n");
        printf("Give choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
              printf("Give authors name:");
              gets(author_name);
              find_books_of_author(books,size,author_name);
            case 2:
              printf("Give book title:");
              gets(book_title);
              delete_at_pos(books,size,book_title);
            case 3:
              find_expensive_book(books,size);
            case 4:
                average_price(books,size);
            case 5:
                save_to_file(books,size);
            case 6:
                break;
            default:
               printf("invalid choice!!!!!\n");
        }
    }
}