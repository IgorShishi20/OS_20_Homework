#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
void *my_realloc(void* ptr, size_t size);

int main(){

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = malloc(sizeof(int)*n1);
    int i;
    for(i=0; i<n1; i++){
        //Set each value in a1 to 100
        a1[i]=100;

        //Print each element out (to make sure things look right)
        printf("%d ",a1[i] );
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    a1 = my_realloc(a1,sizeof(int)*n2);
    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.


    if (n2>n1){
        for (int i=n1;i<n2;i++){
            a1[i]=0;
        }
    }
    for(i=0; i<n2;i++){
        //Print each element out (to make sure things look right)
        printf("%d ",a1[i]);
    }
    printf("\n");

    free(a1);
    //Done with array now, done with program :D

    return 0;
}

void* my_realloc(void* ptr,size_t size){
    //if we have NULL pointer - just allocate memory for an array
    if (ptr==NULL){
        return malloc(size);
    }
    else{
        //if size is equal to 0 - we don't need any array anymore
        if (size==0) {
            free(ptr);
            return ptr;
        }
        else{
            //we find how much size we had before realloc
            size_t size_init=malloc_usable_size(ptr);
            //we create new memory block of size size
            void* ptr_2=malloc(size);
            //we find minimum of current size and previous size
            int min=0;
            if(size<=size_init){
                min=size;
            }
            else{
                min=size_init;
            }
            //we copy memory value from previous array to a new array
            ptr_2=memmove(ptr_2,ptr,min);
            return ptr_2;
        }
    }
}