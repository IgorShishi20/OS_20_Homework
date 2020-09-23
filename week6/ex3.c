#include <stdio.h>
#include <stdlib.h>
int N=0;
int Quantum;
int	main	(int	argc,	char	*argv[])
{
    printf("How many processes do we have\n");
    scanf("%d",&N);
    printf("Enter your quantum, please\n");
    scanf("%d",&Quantum);
    int* arr_time=(int*)malloc(sizeof(int)*N);
    int* burst_time=(int*)malloc(sizeof(int)*N);
    int* completion_time=(int*)malloc(sizeof(int)*N);
    int* turn_around_time=(int*)malloc(sizeof(int)*N);
    int* waiting_time=(int*)malloc(sizeof(int)*N);
    int* burst_time_for_changing=(int*)malloc(sizeof(int)*N);
    float average_turnaround_time;
    float average_waiting_time;
    int flag[N];
    for (int i=0;i<N;i++){
        flag[N]=1;
    }
    for (int i=0;i<N;i++){
        printf("When the process number %d",i);
        printf(" starts\n");
        scanf("%d",&arr_time[i]);
        printf("How many time it will consider?\n");
        scanf("%d",&burst_time[i]);
    }
    int sum_turn_time=0;
    int sum_wait_time=0;
    int sum_burst=0;
    for (int i=0;i<N;i++){
        sum_burst+=burst_time[i];
    }
    int j=0;
    for (int i=0;i<N;i++){
        burst_time_for_changing[i]=burst_time[i];
    }
    int iter=0;
    int init_burst_time=burst_time[0];
    for (int i=0;i<N;i++){
        completion_time[i]=0;
    }
    while (iter<sum_burst){
        if (burst_time_for_changing[j]==0 || iter-init_burst_time==Quantum){
            if (burst_time_for_changing[j]==0){
                completion_time[j]=iter;
            }
            init_burst_time=iter;
            j=(j+1)%N;
            while(burst_time_for_changing[j]==0){
                j=(j+1)%N;
                if (iter==sum_burst){
                    break;
                }
            }
        }
        burst_time_for_changing[j]-=1;
        iter++;
    }
    completion_time[j]=sum_burst;
    for (int i=0;i<N;i++){
        turn_around_time[i]=completion_time[i]-arr_time[i];
        waiting_time[i]=turn_around_time[i]-burst_time[i];
        sum_turn_time+=turn_around_time[i];
        sum_wait_time+=waiting_time[i];
    }
    printf("completion time, turn-around time,waiting time for each process\n");
    for(int i=0;i<N;i++){
        printf("%d ",completion_time[i]-1);
        printf(" %d",turn_around_time[i]);
        printf(" %d",waiting_time[i]);
        printf("\n");
    }
    average_turnaround_time=((float)sum_turn_time)/((float)N);
    average_waiting_time=((float)sum_wait_time)/((float)N);
    printf("%6.6f",average_turnaround_time);
    printf(" ");
    printf("%6.6f",average_waiting_time);
}