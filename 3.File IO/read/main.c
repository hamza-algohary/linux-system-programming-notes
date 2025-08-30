#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc , char ** argv){
    if(argc < 2)
        return 0;
    const char* file_path = argv[1];
    //printf("Opening File %s.\n" , file_path);
    int file = open(file_path , O_RDONLY);
    //printf("Finished Reading , the descriptor is %i\n",file);
    if(file == -1){
        //printf("FILE NOT FOUND");
        return -1;
    }
    struct stat info;
    stat(file_path , &info);

    void * buffer = malloc(info.st_size);

    int size;
    int remaining_size = info.st_size;
    do{
        size = read(file , buffer , remaining_size);
        //printf("Reading...\n");
        if(size == -1){
            if(errno == EINTR || errno == EAGAIN)
                continue;
            else{
                perror("Unable to read\n");
                break;
            }
        }
        buffer += size;
        remaining_size -= size;
    }while(size);
    fflush(stdout);
    buffer -= info.st_size;

    //Undefined behaviour if writing size > SSIZE_MAX  
    int write_state = write(STDOUT_FILENO , buffer , info.st_size); 
    printf("\n");
    if(write_state == -1){
        return 1;
    }
    
    return 0;
}