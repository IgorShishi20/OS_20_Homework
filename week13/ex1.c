#include <stdio.h>
int main(void) {
    int N_of_proc;
    int N_of_res;
    scanf("%d",&N_of_proc);
    scanf("%d",&N_of_res);
    FILE* file;
    file=fopen("ex1.txt","r");
    int E[N_of_res];
    for(int i=0;i<N_of_res;i++){
        fscanf(file,"%d",&E[i]);
    }
    int A[N_of_res];
    for (int i=0;i<N_of_res;i++){
        fscanf(file,"%d",&A[i]);
    }
    int C[N_of_proc][N_of_res];
    for(int i=0;i<N_of_proc;i++){
        for(int j=0;j<N_of_res;j++){
            fscanf(file,"%d",&C[i][j]);
        }
    }
    int R[N_of_proc][N_of_res];
    for(int i=0;i<N_of_proc;i++){
        for(int j=0;j<N_of_res;j++){
            fscanf(file,"%d",&R[i][j]);
        }
    }
    int flag=0;
    int term=0;
    int fit=0;
    while ((flag!=1) && (term!=N_of_proc)){
        flag=1;
        for(int i=0;i<N_of_proc;i++){
            fit=0;
            for(int j=0;j<N_of_res;j++){
                if(R[i][j]>A[j]){
                    fit=1;
                    break;
                }
            }
            if(fit==0){
                for(int j=0;j<N_of_res;j++){
                    A[j]+=R[i][j];
                    R[i][j]=99999999;
                }
                term++;
                flag=0;
            }
        }
    }
    FILE* file_2;
    file_2=fopen("ex1_output.txt","w");
    if (flag==0){
        fprintf(file_2,"NO DEADLOCK");
    }
    else{
        for(int i=0;i<N_of_proc;i++){
            if(R[i][0]!=99999999){
                fprintf(file_2,"%d",i);
                fprintf(file_2," ");
            }
        }
    }
}