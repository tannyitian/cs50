#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long n;
    int a = 0;
    int b = 0;
    int i = 0;
    int count = 0;

    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);
    long n1 = n;

//for check sum
    while (n>=10)
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
        i++;

    }

    if (n*2 >= 10)
    {
        int remains = n*2 % 10;
        a = a + remains + ((n*2 - remains) / 10);
    }

    else
    {
        a = a + n*2;
    }

    int check = a + b;

//printf("%i\n", a);
//printf("%i\n", b);
//printf("%i\n", check);


//for checking card types

if (check%10 == 0)
{
    while (n1>=100)
    {
        int remainder = n1%10;
        n1 = (n1 - remainder) / 10;
        count ++;
    }
    count += 2;

    //printf("%i\n", count);

    if ((n1 == 34 || n1 == 27) && (count==15))
    {
        printf("AMEX\n");
    }
    else if (n1 == 51 || n1 == 52 || n1 ==53 || n1 == 54 || n1 == 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((39 < n1 && n1 < 50) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}

}
