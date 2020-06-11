#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string answer= get_string("text:\n");
    int n=strlen(answer);
    int letter=0;
    int word=1;
    int sentence=0;
    for(int i = 0; i < n; i++){
        if ((answer[i] != 0) && (((answer[i] < 123) && (answer[i] > 96)) || ((answer[i] <91) && (answer[i] > 64)))){
            letter++;
        }
        if ((answer[i]!=' ') && (answer[i+1]==' '))
        {
            word++;
        }
        if (answer[i] == '.' || answer[i] == '?' || answer[i] == '!')
        {
            sentence++;
        }
    }
    float L = (100 * letter) / word;
    float S = (100 * sentence) / word;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    float I = round(index);
    if (I >= 16)
    {
        printf("Grade 16+\n");
    }
    if (I < 1)
    {
        printf("Before Grade 1\n");
    }
    if ((I >= 1) && (I < 16))
    {
        printf("Grade %0.f\n", I);

    }

}
