#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (isupper(c))
            c = tolower(c);
        putchar(c);
        if (c == '\n')
            fflush(stdout); // ??????
    }
    printf("Exiting out of Called program\n");
    exit(0);
}