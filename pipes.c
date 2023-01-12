# include <stdio.h> 
# include <sys/types.h> 
# include <sys/stat.h> 
# include <unistd.h>
#include <fcntl.h>
int main() {
    int fd[2],fdesc; struct stat info;
    pipe(fd); fstat(fd[0],&info);
    printf("st_mode value for pipe fd[0] %d\n",info.st_mode);
    printf("Is FIFO or not %d\n",S_ISFIFO(info.st_mode));
    printf("Is REG file or not %d\n",S_ISREG(info.st_mode));
    fdesc=open("t.txt",O_RDONLY); fstat(fdesc,&info);
    printf("st_mode value for regular file %d\n",info.st_mode);
    printf("Is FIFO or not %d\n",S_ISFIFO(info.st_mode));
    printf("Is REG file or not %d\n", S_ISREG(info.st_mode)); 
}
//output
// st_mode value for pipe fd[0] 4528
// Is FIFO or not 1
// Is REG file or not 0
// st_mode value for regular file 33188
// Is FIFO or not 0
// Is REG file or not 1