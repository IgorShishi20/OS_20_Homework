#include <unistd.h>
#include <stdio.h>
int main(void) {
    char* str="Hello";
    for (int i=0;i<5;i++){
        printf("%c",str[i]);
        sleep(1);
    }
    return 0;
}