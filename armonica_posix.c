#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define NUM_THREADS 4
#define NUM_VAL 100000

static float cont=0.00;

void *Contar(void *threadid)
{
   int i = *((int*)&threadid);

printf("Contar in %d\n",i);

   for(int j=i ; j<=NUM_VAL ; j+=NUM_THREADS)
    {
      cont += (float) 1/j;
      sleep(0.00001);
    }

printf("Contar out %d\n",i);
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

   printf("El valor final del contador = %f\n",cont);

   // Termina el hilo principal, si hay otros hilos, todos terminan
   exit(0);
}
