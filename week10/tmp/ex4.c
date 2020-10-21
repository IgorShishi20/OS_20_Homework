#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
int main()
{
    FILE* fp;
    fp=fopen("ex4.txt","w");
    char *dir=".";
    int depth=0;
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    int N=6;
    long arr[N];
    char* arr_name[N];
    int k=0;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return 0;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)) {
            if(strcmp(".",entry->d_name) == 0 ||
               strcmp("..",entry->d_name) == 0)
                continue;
        }
        else{
            char* str[256];
            long i=stat(".",str);
            fprintf(fp,"%s",str);
            arr[k]=i;
            char* str_name[256];
            arr_name[k]=stat(".",str_name);
            fprintf(fp,"%s",str_name);
        }
    }
    int was_print=0;
    for (int i=0;i<N;i++){
        was_print=0;
        for (int j=0;j<i;j++){
            if (arr[j]==arr[i]){
                was_print=1;
                fprintf(fp,"%s",arr_name[j]);
            }
            if(was_print==1){
                fprintf(fp,"%s",arr_name[i]);
            }
        }
    }
    for (int i=0;i<N;i++){
        fprintf(fp,"%ld\n",arr[i]);
    }
    closedir(dp);
    printf("done.\n");
    fclose(fp);
}