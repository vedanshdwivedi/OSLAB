#include<stdio.h>
#include<unistd.h>
int main()
{	
	int id,id2,id3,id4,id5,id6,a,b,c;
	printf("\nFather id : %d\n",getpid());
	a=getpid();	
	//create two child nodes of this instance
	id=fork(); //child 1
	if(id==0){
		//Child of A
		b=getpid();
		printf("\nChild of Father >> Parent : %d \t\t Child : %d\n",a,b);
		id2 = fork();
		if(id2>0){
			//Child of A
			id3= fork();
			if(id3==0){
				//Grandchild of A
				printf("Grandchild of Father >> Parent : %d \t\t Child : %d\n",b,getpid());
			}
		}else{
			//Grandchild of A
			printf("\nGrandChild of Father >> Parent : %d \t\t Child : %d\n",b,getpid());
		}
	}else if(id>0){
		id6=fork(); //child 2
		if(id6==0){
			//Child of A 
			printf("\nChild of Father >> Parent : %d \t\t Child : %d\n",getppid(),getpid());
			c=getpid();
			id4=fork();
			if(id4==0){
				//GrandChild of A
				printf("\nGrandChild of Father >> Parent : %d \t\t Child : %d\n",c,getpid());
			}else{
				id5=fork();
				if(id5==0){
					//Grandchild of A
					printf("\nGrandChild of Father >> Parent : %d \t\t Child : %d\n",c,getpid());
				}
			}
		}	
	}
	return 0;
} 
