#include <stdio.h>
#include <unistd.h>
#define ML 80 
#include<string.h>
#include <stdlib.h>
int main(void)
{
    int n, int1, int2;
    char line[ML];
    while ((n = read(STDIN_FILENO, line, ML)) > 0)
    {
        line[n] = 0; /* null terminate */
        if (sscanf(line, "%d%d", &int1, &int2) == 2)
        {
            sprintf(line, "%d\n", int1 + int2);
            n = strlen(line);
            if (write(STDOUT_FILENO, line, n) != n)
                printf("write error");
        }
        else if (write(STDOUT_FILENO, "invalid args\n", 13) != 13)
            printf("write error");
    }
    exit(0);
}