//
// Created by Marcus Becker on 2019-07-18.
//

#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void populate_b(float *b);

int main(int argc, char* argv[])
{
    // Prepare the timer
    clock_t start, end;
    double cpu_time_used;

    // _________________________ Start clock _________________________
    start = clock();

    // Create pointers to A and b
    double *A;
    float *b;
    double *c;
    double normOfC = 0;

    // Allocate memory for A, b, C
    A = (double *)malloc(1000 * 1000 * sizeof(double));
    b = (float *)malloc(1000 * sizeof(float));
    c = (double *)malloc(1000 * sizeof(double));

    // Populate A and b
    randomT2(A);
    populate_b(b);

    // Go through each row
    for (int i = 0; i<1000; i++){
        for (int ii = 0; ii<1000; ii++){
            if ( i == 0 ){
                c[ii] = 0;
            }
            // Sum whole row
            c[ii] += A[i + ii * 1000] * b[i];

            if (i == 999){
                normOfC += pow(c[ii],2);
            }
        }
    }

    // Finish calculation of the norm by calculating the square root
    normOfC = sqrt(normOfC);

    // _________________________ Stop clock __________________________
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    outputT2(normOfC, cpu_time_used);

    // Free memory of A and b
    free(A);
    free(b);
    free(c);
}


void populate_b(float *b)
{
    for(int i = 0; i<1000; i++)
    {
        b[i] = (float)(i%2) - 0.5f;
    }

}