#include <unistd.h>
#include <stdio.h>
void tee(const char*);
int main(void) {
    char str[1000];
    scanf("%s",str);
    tee(str);
    return 0;
}
void tee(const char* string_arguments){
    char ch=string_arguments[0];
    int ind_of_str=0;
    int flag=0;
    int j=0;
    int n=sizeof(&string_arguments)/sizeof(ch);
    char arr_of_str[n][n];
    char str[n];
    for (int i=0;i<n;i++){
        ch=string_arguments[i];
        if (ch=='"'){
            if (flag==0){
                j=0;
                flag=1;
            }
            else{
                flag=0;
                for (int k=0;k<j;k++){
                    arr_of_str[ind_of_str][k]=str[k];
                    ind_of_str++;
                }
            }
        }
        else{
            if (flag==0){
                if(ch!=' '){
                    printf("Some problems are here");
                }
            }
            else{
                ch=string_arguments[i];
                str[j]=ch;
                j++;
            }
        }
    }
    if (string_arguments[3]==' ' && string_arguments[4]=='-' && string_arguments[5]=='a' && string_arguments[6]==' ') {
        FILE *files[ind_of_str];
        for (int i = 0; i < ind_of_str; i++) {
            files[i] = fopen(&string_arguments[i], "w+");
        }
        FILE *inp = fopen(STDIN_FILENO, "r");
        FILE *out = fopen((const char *) STDOUT_FILENO, "w+");
        int c;
        while ((c=fgetc(inp))!=EOF){
            fputc(c,out);
            for(int i=0;i<n;i++){
                fputc(c,files[i]);
            }
        }
    }
    else{
        FILE* files[ind_of_str];
        for(int i=0;i<ind_of_str;i++){
            files[i]=fopen(&string_arguments[i],"w");
        }
        FILE* inp=fopen(STDIN_FILENO,"r");
        FILE* out=fopen((const char *) STDOUT_FILENO, "w");
        int c;
        while ((c=fgetc(inp))!=EOF){
            fputc(c,out);
            for(int i=0;i<n;i++){
                fputc(c,files[i]);
            }
        }
    }
}