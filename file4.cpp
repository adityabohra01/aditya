/* 
#include <iostream> 
#include <fcntl.h> 
#include <string.h> 
#include <unistd.h>
using namespace std;
int main() {
char a[20]; int cf, fd = open("t.txt",O_RDWR,0);
cout<<"Access control flags"<<(fcntl(fd,F_GETFL) & O_ACCMODE )<<endl;
cout<<"Value of file descriptor fd"<<fd<<endl;
read(fd,a,2); cout<<endl<<a<<endl;
strcpy(a,"66"); write(fd,a,strlen(a));
cout<<"Contents of t.txt\n"; system("cat t.txt"); cout<<endl;
cf=fcntl(fd,F_GETFL);
cf = fcntl(fd,F_SETFL, cf | O_APPEND|O_NONBLOCK);
strcpy(a,"34"); write(fd,a,strlen(a)); cout<<"\n\n"; system("cat t.txt"); }
*/
/* 
# include <fcntl.h> 
# include <unistd.h> 
# include <sys/stat.h> 
# include <string.h>
# include <iostream>
using namespace std;
int main( ) {
int fd = open("d.txt", O_WRONLY, 0);
char a[20]={"rnsit"};
char b[20]={"Hello"};
cout<< lseek(fd,30,SEEK_SET)<<endl; // works like O_APPEND
write(fd, a, strlen(a));
cout<<lseek(fd,-5,SEEK_CUR)<<endl;
write(fd, b, strlen(b));
close(fd); }
*/
/*
# include <unistd.h>
# include <stdio.h>
int main(int argc, char *argv[])
{
if (argc != 3) {
printf("usage: argv[0] <src_file> <dest_file>\n");
return 0;
}
if (link(argv[1], argv[2]) == -1) {
printf("link");
return 1;
}
return 0;
}
*/
/*
#include <sys/types.h> 
#include <unistd.h> 
#include <iostream>
using namespace std;
int main() {
cout<<"UID "<<getuid()<<endl;
cout<<"EUID "<<geteuid()<<endl;
cout<<"GID "<<getgid()<<endl;
cout<<"EGID "<<getegid()<<endl; }
*/
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <error.h>
#include <sys/stat.h> 
#include <pwd.h> 
#include <stdio.h>
int main() {
struct passwd *p;
struct stat statv;
lstat("a.out",&statv);
p = getpwuid(statv.st_uid);
printf(“%s\n”,p->pw_name);
}