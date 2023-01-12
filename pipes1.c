#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
# define MAXLINE 100

int main(void) {
    int n, fd[2]; pid_t pid; char line[MAXLINE];
    if (pipe(fd) < 0) printf("pipe error");
    if ( (pid = fork()) < 0) printf("fork error");
    else if (pid > 0) { //parent
    close(fd[0]); // parent writes to pipe
    write(fd[1], "hello world\n", 12);
    } else { //child
    close(fd[1]); // child reads from pipe
    n = read(fd[0], line, MAXLINE);
    write(STDOUT_FILENO, line, n);
    printf("%d",n);
    } exit(0); 
}
