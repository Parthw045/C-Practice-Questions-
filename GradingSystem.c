#include <stdio.h>
int main()
{
    int phy , che, maths;
    printf("Enter marks in physics :-");
    scanf("%d",&phy);
    printf("Enter marks in Chemistry :-");
    scanf("%d",&che);
    printf("Enter marks in Maths :-");
    scanf("%d",&maths);

    int avg = (phy+che+maths)/3;

    switch (avg/10)
    {
        case 9:
        printf("Grade A");
        break;
        case 8:
        printf("Grade B");
        break;
        case 7:
        printf("Grade C");
        case 6:
        printf("Grade D");
        break;
        case 5:
        printf("Grade E");
        break;
        default:
        printf("Faillll");
    }
    return 0;
}