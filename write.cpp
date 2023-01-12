#include <iostream> 
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[]) {
struct flock fvar;
int fdesc;
    fdesc=open(*++argv,O_RDWR) ;
    fvar.l_type = F_WRLCK;
    fvar.l_whence = SEEK_SET;
    fvar.l_start= 0;
    fvar.l_len = 0;
    fcntl(fdesc, F_SETLK, &fvar);
    int ex; cin>>ex; close(fdesc);
    return 0; 
}