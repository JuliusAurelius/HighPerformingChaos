//
// Created by Georg K. Bettenhausen on 2019-07-11.
//

#include <stdio.h>
#include "output.h"

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        int i=0, numberOfCharacters = 0;
        char *characters = argv[1];

        while(characters[i] != '\0')
        {
            numberOfCharacters++;
            i++;
        }

        outputT1(numberOfCharacters);
    }
}