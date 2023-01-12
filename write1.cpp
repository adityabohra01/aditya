#include <iostream> 
#include <stdio.h>
#include <sys/types.h> 
#include <fcntl.h>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[])
{
int fdesc;
fdesc=open(*++argv,O_WRONLY) ;
lseek(fdesc,0,SEEK_END);
write(fdesc,"99",2);
close(fdesc);
return 0;
}