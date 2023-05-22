#include<stdio.h>
#include<string.h>

int top=-1;
char Stack[4] = {'\0'};

void Push(char x)
{
  	Stack[++top] = x;
  	return;
}

char Pop()
{
   return Stack[top--];
}

int main()
{
    char Str1[4] = {'\0'};
    char Str2[4] = {'\0'};

    strcpy(Str1, "CSE");
    printf("Str1= %s\n", Str1);

    for(int i=0; i<3; ++i)
    {
        Push(Str1[i]);
        printf("Str1[%d] = %c\n", i, Str1[i]);
    }
    printf("\n");

    for(int i=0; i<3; ++i)
    {
        Str2[i] = Pop();
        printf("Str2[%d] = %c\n", i, Str2[i]);
        //printf("\nStack[%d] by Pop()= %c\n", i+1, Pop());
    }

    printf("\nStr2= %s\n", Str2);

    return 0;
}
