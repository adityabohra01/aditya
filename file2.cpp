//Program to store data in binary file and to retrieve it
# include <iostream>    
# include <fcntl.h>   
# include <sys/types.h>    
# include <unistd.h>
# include <sys/stat.h>
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

  umask(0077);
  int fd = open("bin",O_WRONLY|O_CREAT,0700);  
  write(fd,&a,sizeof(int));
  write(fd,b,sizeof(b));
  write(fd,&c,1);
  write(fd,d,sizeof(d));
  write(fd,&e,sizeof(e));
  write(fd,f,sizeof(st)*2);

  close(fd);

  int a1,b1[4];
  char c1,d1[13];
  st e1,f1[2]; int i;

  fd = open("bin",O_RDONLY,0);
  read(fd,&a1,sizeof(int));
  cout<<a1<<endl;
  read(fd,b1,sizeof(int)*4);
  for(i=0;i<4;i++)
 	cout<<b1[i]<<endl;
  read(fd,&c1,1);
  cout<<c1<<endl;
  read(fd,d1,13);
  cout<<d1<<endl;
  read(fd,&e1,sizeof(st));
  cout<<e1.nm<<" "<<e1.usn<<" "<<e1.marks<<endl;
  read(fd,f1,sizeof(st)*2);
  for(i=0;i<2;i++)
	cout<<f1[i].nm<<" "<<f1[i].usn<<" "<<f1[i].marks<<endl;
return 0;
}