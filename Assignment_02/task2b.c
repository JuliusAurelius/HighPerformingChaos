//
// Created by Georg K. Bettenhausen on 2019-07-10.
//
#include <stdio.h>
#include <stdlib.h>
#include "output.h"

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        int n = atoi(argv[1]);
        for (int i = 0; i <= n; i++) {
            outputT2(i);
        }
    }
}

