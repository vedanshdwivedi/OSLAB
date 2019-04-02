//Two way interprocess communication
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
	int a[2],b[2],l1,l2;
	char a1[80],a2[80],b1[80],b2[80];
	pid_t id;
	if((pipe(a) == -1)||(pipe(b) == -1)){
		printf("\nPipes were not established\n");
		return 1;
	}else{
		
		printf("\nEnter data to send to child process\n");
		scanf("%s",a1);
		id=fork();
	}
	if(id>0){
		//Parent Process
		write(a[1], a1, strlen(a1)+1);
		printf("\nParent >> THIS IS A PARENT PROCESS\n");
		printf("\nParent >> DATA SENT BY PARENT SUCCESSFULLY!!\n NOW READING DATA SENT FROM CHILD\n");
		read(b[0], b2, strlen(b1));	
		printf("Parent >> Data read is %s \n",b2);		
	}else{
		//child process
		printf("\nTHIS IS A CHILD PROCESS TRYING TO READ DATA\n");
		read(a[0], a2, strlen(a2));
		printf("\nChild >> DATA IS : %s \n",a2);
		printf("\nChild >> NOW ENTER DATA TO SEND TO PARENT : \n");
		scanf("%s",b1);
		write(b[1], b1, strlen(b1)+1);
		printf("\nChild >> DATA SENT BY CHILD SUCCESSFULLY!!\n");
	}
	return 0;
}
