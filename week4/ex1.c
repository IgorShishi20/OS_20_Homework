#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int N;
    pid_t pid;
    pid = fork();
    if (pid==0){
        printf("This is son, %d",getpid());
        printf("\n");
    }
    else{
        printf("This is parent, %d", getpid());
        printf("\n");
        return 0;
    }
    return 0;
}
