
#include <stdio.h>
#include <stdlib.h>
int N=0;
void first_job(int* arr_time,int* burst_time,int* arrange);
int	main	(int	argc,	char	*argv[])
{
    printf("How many processes do we have\n");
    scanf("%d",&N);
    int* arr_time=(int*)malloc(sizeof(int)*N);
    int* burst_time=(int*)malloc(sizeof(int)*N);
    int* arrange=(int*)malloc(sizeof(int)*N);
    int* completion_time=(int*)malloc(sizeof(int)*N);
    int* turn_around_time=(int*)malloc(sizeof(int)*N);
    int* waiting_time=(int*)malloc(sizeof(int)*N);
    float average_turnaround_time;
    float average_waiting_time;
    for (int i=0;i<N;i++){
        printf("When the process number %d",i);
        printf(" starts\n");
        scanf("%d",&arr_time[i]);
        printf("How many time it will consider?\n");
        scanf("%d",&burst_time[i]);
    }
    first_job(arr_time,burst_time,arrange);
    int start=arr_time[arrange[0]];
    int sum_turn_time=0;
    int sum_wait_time=0;
    printf("completion time, then turn around time, then waiting time\n");
    for (int i=0;i<N;i++){
        completion_time[arrange[i]]=start+burst_time[arrange[i]];
        turn_around_time[arrange[i]]=completion_time[arrange[i]]-arr_time[arrange[i]];
        waiting_time[arrange[i]]=turn_around_time[arrange[i]]-burst_time[arrange[i]];
        start=completion_time[arrange[i]];
        sum_turn_time+=turn_around_time[arrange[i]];
        sum_wait_time+=waiting_time[arrange[i]];
    }
    for(int i=0;i<N;i++){
        printf("%d ",completion_time[i]);
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
void first_job(int *arr_time,int *burst_time,int *arrange)
{
    int arr_time_for_sort[N];
    int burst_time_for_sort[N];
    for (int i=0;i<N;i++){
        arr_time_for_sort[i]= arr_time[i];
        burst_time_for_sort[i]=burst_time[i];
    }
    int curr_time;
    int min_time = 0;
    int wait_for_proc;
    curr_time=1000000;
    for (int i=0;i<N;i++){
        if (curr_time>arr_time[i]){
            curr_time=arr_time[i];
        }
    }
    for (int i = 0; i < N; i++) {
        wait_for_proc=1000000;
        for (int j = 0; j < N; j++) {
            if (wait_for_proc>burst_time_for_sort[j]) {
                if (curr_time >= arr_time_for_sort[j]){
                    wait_for_proc=burst_time_for_sort[j];
                    min_time = j;
                }
            }
        }
        curr_time +=burst_time[min_time];
        printf(" %d",curr_time);
        arrange[i] = min_time;
        arr_time_for_sort[min_time] = 10000000;
        burst_time_for_sort[min_time]=10000000;
    }
}