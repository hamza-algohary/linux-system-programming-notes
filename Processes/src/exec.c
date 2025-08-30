#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    printf("PID = %d\n" , getpid());
    printf("Parent's PID = %d\n" , getppid());

    //execl("/usr/bin/ls" , "ls" , NULL);
    //execlp("ls" , "hello" , "--help" , NULL);

    //char * const args[] = {
    //    "ls",
    //    "/home/hamza",
    //    "-l",
    //    NULL
    //};
    //
    //execv("/usr/bin/ls" , args);

    //execle("/usr/bin/ls" , "ls" , "/home/hamza" , "-a" , NULL , NULL);

    char * const env[] = {
        "HOME=/home/John",
        NULL
    };
    execle("/usr/bin/printenv" , "printenv" , NULL , env);
    printf("Hello\n");
    return 0;
}