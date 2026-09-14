#include <stdio.h>
int main()
{
    int a= 20;
    int b=30;
    int temp;
    printf("Before Swapping : \n");
    printf("a = %d & b=%d \n",a,b);

    temp = a;
    a =b;
    b = temp ;
    printf("After Swapping :\n");
    printf("a = %d & b = %d",a,b);
    
    return 0;
}