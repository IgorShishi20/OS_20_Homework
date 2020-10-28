#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/mman.h>

int main(void) {
    struct stat buff;
    int new_file_src=open("ex1.txt",O_RDWR);
    int file_dest=open("ex1.memcpy.txt", O_RDWR);
    size_t size = lseek(new_file_src, 0, SEEK_END);
    char* adr_src = mmap(NULL, size, PROT_READ, MAP_SHARED, new_file_src, 0);
    ftruncate(file_dest, size);
    char *adr_dest = mmap(NULL, size,  PROT_WRITE, MAP_SHARED, file_dest,0);
    memcpy(adr_dest,adr_src,size);
    close(new_file_src);
    close(file_dest);
    return 0;
}