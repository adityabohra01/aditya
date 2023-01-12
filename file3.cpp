//Program to store data in text file and to retrieve it
# include <iostream>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>
using namespace std;
struct st
{
  char nm[20],usn[20];
  int marks;
};

int main() {
  int a=10,b[]={100,200,300,400};
  char c='h',d[]={"unix program"};
  st e= {"a","1",1}, f[]={ {"b","2",2},{"c","3",3} };
  char z[50]; int i;

  umask(0077);
  int fd = open("text",O_WRONLY|O_CREAT,0700);  
  sprintf(z,"%d",a);
  write(fd,z,strlen(z));
  for(i=0;i<4;i++) {
	sprintf(z,"%d",b[i]);
	write(fd,z,strlen(z));
  }
  sprintf(z,"%c",c);
  write(fd,z,strlen(z));
  write(fd,d,sizeof(d));

  write(fd,&e,sizeof(e.nm));
  write(fd,e.usn,sizeof(e.usn));
  sprintf(z,"%d",e.marks);
  write(fd,z,strlen(z));
return 0;
}