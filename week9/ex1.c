#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <limits.h>
int main() {
    char ch, file_name[25];
    FILE *fp;
    FILE *fp2;
    fp = fopen("C:\\Users\\Innopolis\\CLionProjects\\untitled2\\Input.txt", "r"); // read mode
    fp2=fopen ("C:\\Users\\Innopolis\\CLionProjects\\untitled2\\out.txt","a");
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    int k=0;
    int arr[1000];
    for (int i=0;i<1000;i++){
        arr[i]=0;
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if ((0<=((int)ch-(int)'0')) && (((int)ch-(int)'0')<=9)){
            arr[k]=10*arr[k]+((int)ch-(int)'0');
        }
        if (ch==' '){
            k++;
        }
    }
    int N=100;
    int hit=0;
    int curr[N];
    for (int i=0;i<N;i++){
        curr[i]=0;
    }
    int index[1000];
    for (int i=0;i<1000;i++){
        index[i]=0;
    }
    int in_curr=0;
    int curr_page=0;
    for (int i=0;i<1000;i++){
        curr_page=arr[i];
        in_curr=0;
        for (int j=0;j<N;j++) {
            if (arr[i] == curr[j]) {
                hit++;
                in_curr = 1;
            }
        }
        if (in_curr==1){
            for (int j=0;j<N;j++){
                index[curr[j]]=index[curr[j]]/2;
            }
            int ones=1;
            for (int l=0;l<31;l++){
                ones*=2;
            }
            index[curr_page]=index[curr_page]+ones;
        }
        else{
            //choose to throw
            int min=INT_MAX;
            int to_throw=0;
            for (int j=0;j<N;j++){
                if (curr[j]<min){
                    min=curr[j];
                    to_throw=j;
                }
            }
            curr[to_throw]=arr[i];
            for (int j=0;j<N;j++){
                index[curr[j]]=index[curr[j]]>>1;
            }
            index[curr_page]=index[curr_page] | ( 1<<31);
        }
    }
    int miss=1000-hit;
    printf("%d ",hit);
    printf(" ");
    printf("%d\n",miss);
    fclose(fp);
    fclose(fp2);
}