#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
//for (int i=0;i<3;i++)
for (int i=0;i<5;i++){
fork();       
}
//the number of processes increasing twice for each fork, and the positions of those processes in tree depends on an operating system
sleep(5);
return 0;
}
