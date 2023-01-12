#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // for close( )
#include <stdio.h>
#include <stdlib.h>
// int main()
// {
// int fd;
// fd = open("t.txt", O_WRONLY|O_CREAT,0);
// printf("%d\n",fd);
// close(fd);
// printf("%d",S_IRWXU);
//  // Assuming that t.txt does not exist above program creates the file t.txt.
// // int main()
// // {
// // int fd;
// // fd = open("t1.txt",O_RDONLY|O_TRUNC,0); printf("%d\n",fd);
// // close(fd);
// // }//Even though file is open in read only mode, the trunc flag will remove all the contents of the file
// mode_t oldvalue = umask(S_IXGRP | S_IWOTH | S_IXOTH);
// printf("%d", (int) oldvalue);
// //system("umask");

// } // The above program will create a file t.txt with permission 644.

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
int main() {
   int fd;
   
  //  fd = open("r2.txt",O_RDONLY,0); // filre r2.txt must exist and read permission must be removed form it.
  //  if (fd < 0) {
  //    printf("%d\n",errno);
  //    printf("%s\n", strerror(errno));//prints error message of the number present in errno.
  //  }
  system("umask");
  printf("%d",umask(0077));
  fd=open("a.txt",O_WRONLY|O_CREAT,0777);
  system("ls -l a.txt");
  system("cal dec 2022");
   return 0;
}
