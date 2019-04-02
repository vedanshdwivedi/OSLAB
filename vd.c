#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t id;
	id = fork();
	if(id>0){
		printf("\nParent Process Created, id : %d",getpid());
	}else if(id==0){
		printf("\nChild Process Created with id : %d",getpid());
		printf("\nChild's Parent Process id : %d",getppid());
	}else{
		printf("\nProcess Creation Failed!!");
	}
}
