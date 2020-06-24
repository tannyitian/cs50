#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float dollars;
    int count = 0;
    int array[4];
    const int n = 4;
    array[0] = 25;
    array[1] = 10;
    array[2] = 5;
    array[3] = 1;
    do
    {
        dollars = get_float("Change owed: ");      
    }
    while (dollars <= 0);
    int cents = round(dollars * 100);

    for (int i = 0; i < n; i++)
    {
        while (cents >= array[i])
        {
            cents -= array[i];
            count ++;
        }
    }
    printf("%i\n", count);
}
