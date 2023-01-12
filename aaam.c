#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
int main() {
pid_t pid;
char *p[4]={
(char *)malloc(sizeof(2)), (char *)malloc(sizeof(2)),
(char *)malloc(sizeof(5)) };
strcpy(p[0],"1"); strcpy(p[1],"a"); strcpy(p[2],"aaaa");
p[3]=0;
if ( (pid = fork()) < 0)
printf("Fork error\n");
else
if (pid == 0){
execv("test.o",p);
printf("%d", getpid());
}
sleep(3);
printf("Parent exiting\n");
return 0;
}
