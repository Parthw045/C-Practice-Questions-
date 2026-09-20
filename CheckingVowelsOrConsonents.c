#include <stdio.h>
int main()
{
    char ch;
    printf("Enter a character :-");
    scanf("%c",&ch);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        printf("%c is a vowel",ch);
    }
    else if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    {
        printf("%c is a consonent",ch);
    }
    else{
        printf("Entered character is not a alphabet");
    }
    return 0;
}