//ADVISORY.cpp
#include <iostream> 
#include <stdio.h> 
#include <sys/types.h>
#include <fcntl.h> 
#include <unistd.h> 
using namespace std;
int main(int argc, char *argv[]) {
    struct flock fvar;
    int fdesc;
    while (--argc>0) {
    if ( (fdesc=open(*++argv,O_RDWR) ) == -1) {
    perror("open"); continue;
    }
    fvar.l_type = F_WRLCK;
    fvar.l_whence = SEEK_SET;
    fvar.l_start = 0;
    fvar.l_len = 0;
    while ( fcntl(fdesc, F_SETLK, &fvar) == -1) {
    while ( fcntl(fdesc, F_GETLK, &fvar) != -1 && fvar.l_type != F_UNLCK) {
    cout<<*argv<< " locked by " << fvar.l_pid<<" from "
    <<fvar.l_start<<" for "<<fvar.l_len<<" byte for "<<
    (fvar.l_type==F_WRLCK ? 'w' : 'r') <<endl;
    }// end of last while
}// end of second while
// After using file content
// cout<<"Enter value\n";
// cin>>jk;
    fvar.l_type = F_UNLCK;
    fvar.l_whence = SEEK_SET;
    fvar.l_start = 0;
    fvar.l_len = 0;
    if ( fcntl(fdesc, F_SETLKW, &fvar) == -1) perror("fcntl");
    } // end of while (--argc>0)
    return 0; }
