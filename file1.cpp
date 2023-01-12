# include <iostream> 
# include <string.h> 
# include <fcntl.h> 
#include <unistd.h> 
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
int fd,val=998;
umask(0200);
fd = open("d1.txt",O_WRONLY|O_CREAT,0500);
char z[30]={"happy "}; write(fd, z, strlen(z));
strcpy(z,"12 "); write(fd, z, strlen(z));
strcpy(z,"12.23 "); write(fd, z, strlen(z));
write(fd, &val, sizeof(val));
//information of type integer stored in d1.txt is not readable in nature
close(fd);
fd = open("d1.txt",O_WRONLY, 0);
// d1.txt cannot be opened in write only mode because of the access permission associated with it while creation of it.
if (fd < 0) { cout<<"Error message is\n"<<strerror(errno)<<endl; }
close(fd);
return 0;
}