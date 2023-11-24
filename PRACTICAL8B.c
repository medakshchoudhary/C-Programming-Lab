#include <stdio.h>
#include <string.h>
int main() 
{
    char str[100];
    printf("Enter the value of string :-");
    gets(str); 
    int i, len, ispallindrome = 0;
    len = strlen(str);
    for (i = 0; i < len; i++) 
    {
        if (str[i] != str[len - i - 1]) {
            ispallindrome = 1;
            break;
        }
    }

    if (ispallindrome)
        printf(" String is not palindrome");
    else
        printf("String is palindrome");
        
    return 0;
}