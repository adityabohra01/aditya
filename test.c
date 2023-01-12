//test.c
# include <stdio.h> 
# include <sys/wait.h>
# include <stdlib.h> 
# include <unistd.h>
int main(void) {
    pid_t pid;
    if ((pid = fork()) < 0)
    printf("fork error\n");
    else
    if (pid ==0)
    {
    if (execl("/Users/kritibohra/aditya", "testinterp.sh", "myarg1", "MY ARG2", (char *)0) < 0 )
    //if 2nd argument “testinterp.sh” is skipped then “myarg1” … cannot be printed
    printf("execl error\n");
    }
    if (waitpid(pid,NULL,0) < 0)
    printf("waitpid error\n");
    exit(0); 
}