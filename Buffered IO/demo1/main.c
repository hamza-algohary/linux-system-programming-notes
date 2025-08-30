#include <stdio.h>

int main(int argc , char** argv){
    
    if(argc < 2){
        printf("Too few arguments\n");
        return 0;
    }
    
    FILE * file = fopen(argv[1] , "r");
    
    if(!file){
        printf("%s not found" , argv[1]);
        return -1;
    }
    return 0;
}