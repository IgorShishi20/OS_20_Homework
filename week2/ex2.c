#include <stdio.h>
#include <string.h>
int main(){
    char s[2000];
    gets(s);
    char str[2000]="";
    for(int i=0;i<strlen(s);i++){
        str[i]=s[strlen(s)-i-1];
    }
    printf("%s",str);
    return 0;
}
