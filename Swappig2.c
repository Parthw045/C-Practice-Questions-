#include <stdio.h>
int main()
{
    int a = 10;
    int b = 20;
    printf("Before Swapping :-");
    printf("a = %d & b = %d \n",a,b);

    //swapping 
    a= a+b;
    b= a-b;
    a= a-b;
    printf("After Swapping :-");
    printf("a = %d & b = %d",a,b);


    return 0;
}