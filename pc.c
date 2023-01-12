#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 80
int main(void)
{
    char line[MAXLINE];
    FILE *fpin;
    fpin = popen("./myuclc", "r");
    for (;;)
    {
        printf("prompt> ");
        fflush(stdout);
        if (fgets(line, MAXLINE, fpin) == NULL) /* read from pipe */
            break;
        fputs(line, stdout);
    }
    pclose(fpin);
    printf("Exiting out of Calling program\n");
    exit(0);
}