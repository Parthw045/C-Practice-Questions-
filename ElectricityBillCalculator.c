#include <stdio.h>
int main()
{
    // suppose 1 unit charges is 38.66rs
    int unit;
    printf("Enter units consumed this month :-");
    scanf("%d",&unit);

    float bill = unit * 38.66 ;
    printf("You have to pay %f Rs",bill);

    return 0;
}