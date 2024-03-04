#include <stdio.h>

int main() {
    char c;
    printf("Enter any alphabetic character : "); 
    scanf("%c", &c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ) 
    {
        printf("Entered alphabetic character is a vowel");
    }
    else (printf("Entered alphabetic character is a consonant or any other symbolic character"));
    return 0;
}