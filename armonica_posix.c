#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define NUM_THREADS 2
#define NUM_VAL 100000

static float cont[NUM_THREADS];

void *Contar(void *threadid)
{
   int i = *((int*)&threadid);

   for(int j=i ; j<=NUM_VAL ; j+=NUM_THREADS)
    {
      cont[i-1] += (float) 1/j;
    }

   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   // Arreglo de TIDs (identificadores de hilo)
   pthread_t threads[NUM_THREADS];

   int rc, t;
   int status;

   for(t=1; t<=NUM_THREADS; t++){
      rc = pthread_create(&threads[t], NULL, Contar, (void *)t);

      // Si pthread_create regresa un valor != 0 entonces hubo un error
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   for(t=1;t<=NUM_THREADS; t++)
      pthread_join(threads[t],(void*)&status);
int index = 1;
    while(index<NUM_THREADS)
    {
        cont[0] += cont[index++]; 
    }

   printf("El valor final del contador = %f\n",cont[0]);

   // Termina el hilo principal, si hay otros hilos, todos terminan
   exit(0);
}
