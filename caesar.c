#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//formula is Ci = (Pi + k)%26 where Pi is the index of each alphabet. Need to convert ascii to alphabetical index
// 65 to 90 is A to Z, 97 to 122 is a to z
//argv[1] is a string not an integer, convert it to int using atoi

int key;

int main(int argc, string argv[])
{

    if (argc != 2) //making sure that argc is always 2
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    for (int i = 0; i < strlen(argv[1]); i++)// check if each character in argv[1] is a digit
    {
        if (isdigit(argv[1][i]) == 0) //0 means false
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }

   string s = get_string("plaintext: ");
   printf("ciphertext: ");

   //convert argv[1] to integer since it is string
   key = atoi(argv[1]);


   for (int i = 0; i<strlen(s); i++)
   {
       if (ispunct(s[i]) || isspace(s[i])) //checking if is punctuation or blankspace
       {
           printf("%c", s[i]);
       }
       else
       {
           if(isupper(s[i]))
           {
               printf("%c", ((s[i] - 'A')+key) % 26 + 'A');

           }
           else
           {
               printf("%c",((s[i] - 'a')+key) % 26 + 'a');
           }
       }
   }
   printf("\n");
}