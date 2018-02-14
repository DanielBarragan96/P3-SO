#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h> 

#define NUM_THREADS 2
#define NUM_VAL 100000
#define DIV 100000
#define SHM_SIZE 256

//	http://users.cs.cf.ac.uk/Dave.Marshall/C/node27.html
	float *shm, *s;
	key_t key = 1000;	/* key to be passed to shmget() */ 
	int shmflg; 		/* shmflg to be passed to shmget() */ 
	int shmid; 		/* return value from shmget() */ 
	int size=SHM_SIZE; 	/* size to be passed to shmget() */ 

void Contar(int i)
{
	float cont = 0.0;
	key_t key = 1000;
	
	if ((shmid = shmget(key, sizeof(float)*NUM_THREADS, IPC_CREAT|0666)) < 0) {
        perror("shmget");
        exit(1);
	}

	if ((shm = shmat(shmid, NULL, 0)) == (float *) -1) {
        perror("shmat");
        exit(1);
	}
	   for(float j= (float) i ; j<=NUM_VAL ; j+=NUM_THREADS)
	    {
	      cont += 1/j;
	    }
	s=shm;
	s=s+i-1;
	*s=cont;
	exit(0);
}

int main (int argc, char *argv[])
{
   // Arreglo de TIDs (identificadores de hilo)

   int rc, t, p;
   int status;
   float returned = 0.0;
    
    if ((shmid = shmget(key, sizeof(float)*NUM_THREADS, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (float *) -1) {
        perror("shmat");
        exit(1);
    }
   for(t=1; t<=NUM_THREADS; t++){
        p = fork();
		if(!p)
		{
			Contar(t);
		}
    }

    for(int al=1; al<=NUM_THREADS; al++)
        wait(&status);
   
    if ((shm = shmat(shmid, NULL, 0)) == (float *) -1) {
        perror("shmat");
        exit(1);
    }
	
	s=shm;
	int index=1;
	while(index<=NUM_THREADS)
	    {
		returned += *s;
		index++;
		s++; 
	    }
	
   printf("El valor final del contador = %f\n",returned);

   exit(0);
}
