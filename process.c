#include<stdio.h>
#include<unistd.h>
int main()
  {
     int id;
     id=fork();
     if(id>0)
{
   printf("this is parent process\n id is %d\n",getpid());
}
  else if(id==0)
{
   printf("child process is created\n id is %d\n",getpid());
printf("child's parent process id is %d\n",getppid());
}
else
{
   printf("process creation is failed");
}
return 0;
}
