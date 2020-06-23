#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    //Outer for loop for rows
    for (int i = 0; i < n; i++)
    {
        //Inner for loop for columns
        for (int j = 0; j<(n+i+3); j++)
        {
            if (j<(n-i-1))
            {
                printf(" ");
            }
            //Putting spaces in middle 2 positions
            else if (j == n || j == n + 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }  
}
