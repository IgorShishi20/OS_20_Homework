#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#define N 10
void *thread_function();
int j=0;
pthread_t* threads;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int main(int argc)
{
    threads=malloc(sizeof(pthread_t)*N);
    int i;
    j=0;
    for(i=0; i < N; i++)
    {
        pthread_create(&(threads[i]), NULL, &thread_function,NULL);
    }
    pthread_exit(NULL);
}
void *thread_function(void * ptr) {
    while(1){
        if (pthread_equal(pthread_self(),threads[j])){
            printf("Created thread number %d\n",j+1);
            printf("Thread number in OS is %ld\n", threads[j]," \n");
            printf("Thread exit\n");
            j++;
            break;
        }
    }
}