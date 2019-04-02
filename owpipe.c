//one way interprocess communication using pipes
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int a[2],l1,l2;
	pid_t id;
	//a[0] is for reading and a[1] is for writing
	char arr1[80],arr2[80];
	if(pipe(a) == -1){
		printf("\nPipe Creation Failed\n");
		return 1;
	}else{
		printf("\nEnter Data to Pass : ");
		scanf("%s",arr1);		
		id = fork();
	}
	if(id>0){
		printf("\nPARENT IS PASSING DATA\n");
		write(a[1], arr1, strlen(arr1)+1);
	}else if(id==0){
		printf("\nDATA IS BEING RECEIVED BY CHILD\n");
		read(a[0], arr2, strlen(arr1));
		printf("DATA READ SUCCESSFULLY\n DATA IS : %s\n",arr2);
	}else{
		printf("\nThere was an error in creating the process\n");
	}	
	return 0;
}
