/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    char* hello = "hello";
    while(*hello != '\0'){
        printf("%c\n",*hello);
        *hello++;
    }
    return 0;
}