#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int count=0;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    do
    {
         dollars = get_float("Change owed: ");
        
    }
    while (dollars<0);

    int cents = round(dollars * 100);

    for (int c = cents; c>=quarters; c=c-quarters)
    {
        cents = cents-quarters;
        count++;
    }
    
    for (int c = cents; c>=dimes; c=c-dimes)
    {
        cents = cents-dimes;
        count++;
    }

    for (int c = cents; c>=nickels; c=c-nickels)
    {
        cents = cents-nickels;
        count++;
    }

    for (int c = cents; c>=pennies; c=c-pennies)
    {
        cents = cents-pennies;
        count++;
    }

    printf("%i\n", count);
}
