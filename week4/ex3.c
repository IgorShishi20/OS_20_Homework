#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
    while(1){
        char str[256];
        scanf("%s",str);
        system(str);
    }
    return 0;
}
