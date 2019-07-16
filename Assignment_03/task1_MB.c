//
// Created by Marcus Becker on 2019-07-16.
//

#include <stdio.h>
#include "output.h"

int main(int argc, char* argv[])
{
    // Check if argv was used
    if(argc == 2)
    {
        // Count elements in array
        int numChar = 0;
        char *characters = argv[1];

        while(characters[numChar] != '\0')
        {
            numChar++;
        }
        outputT1(numChar);
    }
    return 0;
}