#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter number:-");
    scanf("%d",&a);
    printf("Enter exponent value:-");
    scanf("%d",&b);

    int result = a;
    for(int i=1 ; i < b; i++ )
    {
        result = result*a;
    }
    printf("a^b = %d",result);
    return 0;
}