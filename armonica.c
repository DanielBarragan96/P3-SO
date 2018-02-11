#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(int argc,char *argv[])
{
	
	unsigned int i,n;
	double s=0.0;
	long long start_ts;
	long long stop_ts;
	float elapsed_time;
	long lElapsedTime;
	struct timeval ts;

	if(argc==1)
	{
		n=UINT_MAX-1;
		printf("El valor de n es %u\n",n);
	}
	else if(argc==2)
	{		
		n=atoi(argv[1]);
		printf("El valor de n es %u\n",n);
	}
	else
	{
		fprintf(stderr,"Error en los argumentos\n");
		exit(1);
	}
	
	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec * 1000000 + ts.tv_usec; // Tiempo inicial

	for(i=1;i<=n;i++)
		s=s+1.0/(double) i;
	

	gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec * 1000000 + ts.tv_usec; // Tiempo final

	elapsed_time = (float) (stop_ts - start_ts)/1000000.0;
	printf("Tiempo = %2.2f segundos\n",elapsed_time);

	printf("s=%f\n",s);
	
}
