#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main(int argc)
{
    char ch;
    char *argv[]={"/bin/sh", 0};
    char *envp[]={0};
    while(1){
        char str[256];
        scanf("%s",str);
        execv("/bin/sh",strsep(str,' '));
    }
    return 0;
}