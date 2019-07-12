//
// Created by Georg K. Bettenhausen on 2019-07-12.
//

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "output.h"

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    double *A = malloc(1000000 * sizeof(double));
    float *b = malloc(1000 * sizeof(float));

    randomT2(A);

    for(int i = 0; i < 1000; i++) {
        if (i % 2 == 0)
            b[i] = 0.5f;
        else
            b[i] = -0.5f;
    }

    double *c = malloc(1000 * sizeof(double));

    for(int i = 0; i < 1000; i++) {
        double sumPerRow = 0;
        for (int j = 0; j < 1000; j++) {
            sumPerRow += A[1000*i + j] * b[j];
        }

        c[i] = sumPerRow;
    }

    double normOfC = 0;
    for(int i = 0; i < 1000; i++)
    {
        normOfC += pow(c[i],2);
    }

    normOfC = sqrt(normOfC);


    end = clock();

    cpu_time_used = (double) end-start/CLOCKS_PER_SEC;

    outputT2(normOfC, cpu_time_used);

}