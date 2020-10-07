#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
    //the virtual memory and physical memory size was nearly 112 MB. Virtual memory size was slightly greater than physical memory
    //the top command show the virtual memory, res, shr - virtual memory increased till 112 MB. Also there were 5 another processes
    //and whole amount of used and free memory
    for (int i=0;i<10;i++){
        int* ptr=malloc(1024*10240);
        memset(ptr,0,1024*10240);
        sleep(1);
    }
}