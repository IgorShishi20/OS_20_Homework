#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
    int a;
    a=INT_MAX;
    float b;
    b=FLT_MAX;
    double c;
    c=DBL_MAX;
    printf("%d\n",a);
    printf("%f\n",b);
    printf("%lf\n",c);
    return 0;
}