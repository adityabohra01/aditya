# include <stdio.h> 
# include <stdlib.h> 
# include <unistd.h>
int glob=6;
int main(void) {
int var; pid_t pid;
var=88;
printf("before fork\n");
if ((pid=vfork()) < 0)
printf("vfork error");
else
if (pid == 0)
{
glob++;
var++;
printf("from child pid = %d, glob = %d, var = %d\n", getpid(), glob,
var);
sleep(2);
_exit(0);
}
printf("from parent pid = %d, glob = %d, var = %d\n", getpid(), glob,
var);
return 0;
}