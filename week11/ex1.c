#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
int main(){
    struct stat buf;
    int file=open("ex1.txt",O_RDWR);
    char *str="This is a nice day\n";
    ftruncate(file, strlen(str));
    char *adr=mmap(NULL,strlen(str),PROT_WRITE,MAP_SHARED,file,0);
    strncpy(adr,str,strlen(str));
    munmap(adr,strlen(str));
    return 0;
}