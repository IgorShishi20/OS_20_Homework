#include <stdio.h>
void reverse(int *a,int *b){
    int curr=*a;
    *a=*b;
    *b=curr;
}

int main(){

    int a;
    int b;
    scanf("%d",&a);
    scanf("%d", &b);
    reverse(&a,&b);
    printf("%d\n",a);
    printf("%d",b);
    return 0;
}