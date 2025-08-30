#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(){
    auto file = open("open/main.cpp",O_RDWR);
    if(file == -1)
        printf("ERROR\n");
    
    // Create A File
    auto file2 = open("test" , O_CREAT , S_IRWXU | S_IRWXG);
    if(file2 == -1)
        printf("Couldn't Create A File");
    return 0;
}