#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
    //the virtual memory and physical memory size was nearly 100 MB. Virtual memory size was slightly greater than physical memory
    for (int i=0;i<10;i++){
        int* ptr=malloc(1024*10240);
        memset(ptr,0,1024*10240);
        sleep(1);
    }
}