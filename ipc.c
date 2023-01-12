#include <sys/ipc.h>
#include <stdio.h>
int main() {
key_t semkey;
semkey = ftok("d.txt", 'a');

 printf("key is %d\n",semkey);
}