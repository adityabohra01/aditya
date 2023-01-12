# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <iostream>
using namespace std;
int main() { // reading data from text file using read API.
int fd;
fd = open("d.txt",O_RDONLY,0); char z[500];
// cout<<read(fd, z, 6)<<endl; // to read 6 characters(i,e 1,2,.,....), which belongs to double value
// cout<<z; z[0]='\0';
// cout<<read(fd, z, 6)<<endl; // to read 5 characters, which belongs to string “happy”
// cout<<z; z[0] = '\0';
// cout<<read(fd, z, 11)<<endl; // to read 10 characters, which belongs to integer value.
//cout<<z;
//cout<<z;
//gives garbage value cout<<read(fd, z, 500)<<endl; // to read 6 characters(i,e 1,2,.,....), which belongs to double value
int v = read(fd, z, 500);  
z[v]='\0'; 
cout<<v<<endl;
}
