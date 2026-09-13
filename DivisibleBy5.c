#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number :-");
    scanf("%d",&num);
    if(num%5 ==0)
    {
        printf("%d is divisible by 5",num);
    }
    else{
        printf("Not divisible by 5");
    }
    return 0;
}