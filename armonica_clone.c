#define _GNU_SOURCE    
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

#define FIBER_STACK 8192
#define NUM_THREADS 2
#define NUM_VAL 100000

static float cont[NUM_THREADS];
int a = 0;
int status;

int contar()
{
    int i = ++a;

    for(int j=i ; j<=NUM_VAL ; j+=NUM_THREADS)
    {
      cont[i] += (float) 1/j;
    }
    printf("Valor %d: %f\n",i,cont[i]);
    exit(0);
}

int main (int argc, char *argv[])
{
    void * stack;
    stack = malloc(4*FIBER_STACK);
    if(!stack) {
        printf("The stack failed\n");
        exit(0);
    }

   int rc, t, p;
   int status;

   for(t=1; t<=NUM_THREADS; t++){
       int algo = clone(&contar, (char *)stack + (t)*FIBER_STACK, CLONE_VM, 0, NULL);
        usleep(1000);
   }
    for(int count=1; count<=NUM_THREADS; count++)
        wait(&status);

    for(int count=1; count<=NUM_THREADS; count++)
        cont[0] += cont[count];   

   printf("El valor final del contador = %f\n",cont[0]);
   free(stack);
   exit(0);
}
