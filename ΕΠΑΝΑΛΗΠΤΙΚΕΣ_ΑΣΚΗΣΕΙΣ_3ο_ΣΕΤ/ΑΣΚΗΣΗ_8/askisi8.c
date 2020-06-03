#include<stdio.h>
#include <windows.h>
#include <locale.h>
#pragma execution_character_set( "/utf-8" );

int greek_uppercase()
{
    SetConsoleOutputCP(65001);
    char table[] = {'?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?','?'};
    char letter;
    printf("Give letter:");
    scanf("%c",&letter);
    for(int i=0;i<24;i++)
    {
        if(letter==table[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Greek uppercase %d", greek_uppercase());
    return 0;
}