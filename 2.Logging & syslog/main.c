#include <stdio.h>
#include <syslog.h>

int main(int argc , char ** argv){
	if(argc < 2){
		printf("An Application that does nothing.\n");
		return 0;
	}else{
		openlog(NULL , 0 , LOG_USER);
		syslog(LOG_ERR , "Too Many Arguments.");
		return 1;
	}
}
