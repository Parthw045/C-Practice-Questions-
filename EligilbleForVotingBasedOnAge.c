#include <stdio.h>
int main()
{   
    int age;
    printf("Enter your age :-");
    scanf("%d",&age);

    if(age >= 18)
    {
        printf("You are eligible for voting");
    }
    else{
        printf("Sorry !! you aren't eligible for voting.");
    }
    
    return 0;
}