//
// Created by Georg K. Bettenhausen on 2019-07-10.
//

#include <stdlib.h>
#include "output.h"

int int_comp(const void *arg1, const void *arg2)
{
    int one = * (int *) arg1;
    int two = * (int *) arg2;

    if(one < two)
        return -1;
    else if(one > two)
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        int n = atoi(argv[1]);
        if(0 < n && n < 100)
        {
            int* ints = malloc(sizeof(int) * (n+1));

            for(int i = 0; i  <= n; i++)
            {
                ints[i] = n - i;
            }

            qsort(ints, n + 1, sizeof(int), int_comp);

            outputT5(ints, n +1);

            free (ints);
        }
    }
}