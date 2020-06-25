#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long n;
    int a = 0;
    int b = 0;
    int count = 0;

    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);
    long n1 = n;
    long n2 = n;

//find length of number

 while(n1>0)
 {

      n1=n1/10;
      count+=1;

 }

 printf("%i\n", count);

 for (int i = 0; i < count ; i++)
 {
      int remainder = n%10;
      n = (n - remainder) / 10;

      if (i % 2 != 0)
      {
              if (remainder*2 >= 10)
            {
                int remain = (remainder*2)%10;
                a = a + remain + ((remainder*2 - remain) / 10);
            }
            else
            {
                 a = a + remainder*2;

            }
      }
    else
    {
         b = b + remainder;
    }

 }

//printf("%i\n", a);
//printf("%i\n", b);
//printf("%i\n", a+b);

int check = a + b;


if (check % 10 == 0)
{
    while (n2 > 100)
    {
        int remains = n2 % 10;
        n2 = (n2 - remains) / 10;
    }
    
    printf("%li\n", n2);

    if ((n2 == 34 || n2 == 37) && (count==15))
    {
        printf("AMEX\n");

    }
    else if ((n2 == 51 || n2 == 52 || n2 ==53 || n2 == 54 || n2 == 55) && (count == 16))
    {
        printf("MASTERCARD\n");

    }
    else if ((39 < n2 && n2 < 50) && (count == 13 || count == 16))
    {
        printf("VISA\n");

    }
    
}

else
    {
        printf("INVALID\n");
    }

}
