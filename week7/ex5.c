#include <stdio.h>
#include <stdlib.h>
int main() {
    char **s;
    //we can also solve segmentation fault problem by introducing foo as a char pointer char* foo
    char foo[] = "Hello World";
    //we initialize memory for s pointer so s is now some particular address
    s=malloc(sizeof(foo));
    //we assign value from address s to foo
    *s = foo;
    //we print s as pointer to something
    printf("s is %p\n",s);
    //we again assign value from address s to foo
    s[0]=foo;
    //we print s[0] as string (character array)
    printf("s[0] is %s\n",s[0]);
    return(0);
}