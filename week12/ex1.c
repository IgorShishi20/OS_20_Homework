#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/mman.h>

int main(void) {
    int randomfileint = open("/dev/random", O_RDONLY);
    FILE* ex1=fopen("ex1.txt","w");
    if (randomfileint < 0)
    {
        printf("%s","There are problems");
    }
    else
    {
        char Random_string[20];
        size_t str_length = 0;
        while (str_length < sizeof Random_string)
        {
            ssize_t result = read(randomfileint, Random_string + str_length, (sizeof Random_string) - str_length);
            if (result < 0)
            {
                printf("%s","Some problems are here");
            }
            str_length += result;
        }
        fprintf(ex1,"%s",Random_string);
        close(randomfileint);
    }
    return 0;
}
