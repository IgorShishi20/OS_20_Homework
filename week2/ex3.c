#include <stdio.h>
#include <string.h>
void triangle(int N){
    for (int i=0;i<N;i++) {
        char si[2*N+1];
        for (int j=0;j<N-i;j++){
            si[j]=' ';
        }
        for (int j=0;j<2*i+1;j++){
            si[N-i+j]='*';
        }
        for (int j=0;j<N-i;j++){
            si[N+i+1+j]=' ';
        }
        printf("%s\n",si);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%d\n",N);
    triangle(N);
    return 0;
}