#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h> 

#define NUM_THREADS 4
#define NUM_VAL 100000
#define DIV 100000
#define SHM_SIZE 1024


void Contar( int i, int shmiders)
{
float cont = 0;

printf("Contar in %d\n",i);

   for(int j=i ; j<=NUM_VAL ; j+=NUM_THREADS)
    {
      cont += (float) 1/j;
    }

printf("Contar out %d\n",i);
cont *= DIV;
return (int) cont;
}

int main (int argc, char *argv[])
{
   // Arreglo de TIDs (identificadores de hilo)
   pthread_t threads[NUM_THREADS];

   int rc, t, p;
   int status;
float returned = 0.0;

   for(t=1; t<=NUM_THREADS; t++){
        p = fork();
		if(!p)
		{
			Contar(t, shmget());
		}
            wait(&status);
			returned += (float) status / DIV;
			printf("WIFE IN %f\n",returned);
   }

   for(t=1;t<=NUM_THREADS; t++)
    {
        wait(NULL);
    }

   printf("El valor final del contador = %f\n",returned);

   // Termina el hilo principal, si hay otros hilos, todos terminan
   exit(0);
}
