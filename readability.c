#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letters = 0;
int words = 0;
int sentences = 0;

//consider using isspace() to check for blank space and isalpha() to check for alphabetic character

int main(void)
{
  string input  = get_string("Text: ");

  for (int i = 0; i < strlen(input); i++)
  {
     if (isalpha(input[i]))
      letters ++;
  }
  for (int i = 0; i < strlen(input); i++)
  {
      if (isspace(input[i]))
      words ++;
  }
  words++;

  for (int i = 0; i < strlen(input); i++)
  {
      if ((input[i]) == '!' || (input[i]) == '.'|| (input[i]) == '?' )
      sentences ++;
  }

  printf("%i letter(s)\n", letters);
  printf("%i word(s)\n", words);
  printf("%i sentence(s)\n", sentences);




  float L = (float)letters/words * 100;
  float S = (float)sentences/words * 100;

  int index = round((0.0588 * L) - (0.296 * S) - 15.8);


  //printf("%f\n", L);
  //printf("%f\n", S);
  //printf("%i\n", index);

  if(index < 1)
  {
    printf("Before Grade 1\n");
  }
  else
  {
    printf("Grade %i\n", index);
  }


}





