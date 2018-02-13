#define _GNU_SOURCE    
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define FIBER_STACK 8192
#define NUM_THREADS 4
#define NUM_VAL 100000

static float cont[NUM_THREADS];
int a = 0;

int contar()
{
    int i = ++a;
    printf("Contar in %d\n",i);

    for(int j=i ; j<=NUM_VAL ; j+=NUM_THREADS)
    {
      cont[i] += (float) 1/j;
    }

    printf("Contar out %d\n",i);
    exit(0);
}

int main (int argc, char *argv[])
{
    void * stack;
    stack = malloc(FIBER_STACK);
    if(!stack) {
        printf("The stack failed\n");
        exit(0);
    }

   int rc, t, p;
   int status;

   for(t=1; t<=NUM_THREADS; t++){
       int algo = clone(&contar, (char *)stack + FIBER_STACK, CLONE_VM, 0, NULL);
        printf("Algo %d\n",algo);
   }

    while(1);
   printf("El valor final del contador = %f--------\n",cont[1]);
   free(stack);
   exit(0);
}
