#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
   if ((argc != 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
        int length = strlen((argv[1]));
        int number = atoi(argv[1]);
        int key = number;
        int digit = 0;
        while (number != 0)
        {
                number /= 10;
                digit++;
        }
        if (length != digit)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
        string message = get_string("plaintext: \n");

        printf("ciphertext:");

        char output;

        for (int i = 0; i < strlen(message); i++)
        {
            if ((message[i] < 123) && (message[i] > 96))
            {
            output = ((message[i] + key - 97) % 26) + 97;

            }
            else if((message[i] <91) && (message[i] > 64))
            {
            output = ((message[i]+ key + 65) % 26) + 65;

            }
            else{

            output = message[i];

            }

        printf("%c", output);
        }

        printf("\n");
        }
    }
}
