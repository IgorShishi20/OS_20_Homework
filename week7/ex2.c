#include <stdio.h>
#include <stdlib.h>


int	main	(int	argc,	char	*argv[]) {
    //we read N - number of elements of the array
    int N = 0;
    printf("How many elements we have\n");
    scanf("%d", &N);
    //we allocate memory for N integers in an array
    int* arr=malloc(sizeof(int)*N);
    //we fill the array
    for (int i=0;i<N;i++){
        arr[i]=i;
    }
    //we print array
    for (int i=0;i<N;i++){
        printf("%d\n",arr[i]);
    }
    //we deallocate memory
    free(arr);
}