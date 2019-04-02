#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<semaphore.h>
int main()
{
  int pid,mutex=1;
  int semid;               /* semid of semaphore set */
  key_t key = 1234; /* key to pass to semget() */
  int nsems = 1; /* nsems to pass to semget() */
  semid=semget(key,nsems,IPC_CREAT|0666);
  if (semid<0) 
  { 
    printf("Semaphore creation failed ");
  }
  if ((pid = fork()) < 0) 
  {
    perror("fork");
    return 1;
  }
  else if(pid==0)
  {
    sem_wait(&semid);
    printf("IN CHILD PROCESS :\n");
    mutex++; 
    printf("value of shared variable =%d",mutex);
    sem_post(&semid);
    return 0;
  }
  sem_wait(&semid);
  printf("IN PARENT PROCESS :\n");
  mutex--;
  printf("value of shared variable =%d",mutex);
  sem_post(&semid);
  return 0;
} 
