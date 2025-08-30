#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>

int main(){

    pid_t pid = fork();

    assert(pid != -1);

    if(pid > 0)
        printf("I am the parent\n");
    else if(pid == 0)
        printf("I am the child\n");

    // Now there are two processes sharing the same terminal.
    return 0;
}