#include <stdio.h>
#include <stdbool.h>
void swap(int *a,int *b){
    int temp;
    temp= *a;
    *a= *b;
    *b= temp;
}
int bubble_sort(int arr[],int N){
    bool need_to_swap;
    do{
        need_to_swap=false;
        for (int i=1;i<N;i++){
            if(arr[i-1]>arr[i]){
                swap(&arr[i],&arr[i-1]);
                need_to_swap=true;
            }
        }
        N--;
    }
    while(!need_to_swap);
    return 0;
}
int main(){
    int N;
    scanf("%d",&N);
    int array[N];
    for(int i=0;i<N;i++){
        scanf("%d",&array[i]);
    }
    bubble_sort(array, sizeof(array)/ sizeof(array[0]));
    for (int i=0;i<5;i++){
        printf("%d ",array[i]);
    }
    return 0;
}