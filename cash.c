#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int count = 0;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    do
    {
        dollars = get_float("Change owed: ");
        
    }
    while (dollars < 0);
    int cents = round(dollars * 100);

    while (cents >= quarters)
    {
        cents = cents - quarters;
        count++;
    }
    while (cents >= dimes)
    {
        cents = cents - dimes;
        count++;
    }
    while (cents >= nickels)
    {
        cents = cents - nickels;
        count++;
    }
    while (cents >= pennies)
    {
        cents = cents - pennies;
        count++;
    }
   
    printf("%i\n", count);
}
