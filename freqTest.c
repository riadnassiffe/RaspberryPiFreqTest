#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
	int limit;

	if (argc == 0) {
		printf("%d", argc);
		printf("1 argument\n");
		return(0);
	    }else {
		limit = atoi(argv[1]);
	}
	int i;
	struct timespec startCpuTime, stopCpuTime, startTotalTime, stopTotalTime;

	clock_gettime(CLOCK_MONOTONIC, &startTotalTime);	
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &startCpuTime);
	        

	for(i=0;i<limit;i++)
	    log(2*i)+exp(i)+pow(2,i)*i;



	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &stopCpuTime);
	clock_gettime(CLOCK_MONOTONIC, &stopTotalTime);    	

	double cpuUsedTime = ((double) (stopCpuTime.tv_sec - startCpuTime.tv_sec)
			+ (stopCpuTime.tv_nsec - startCpuTime.tv_nsec)
					/ (double) 1000000000L);
	double totalUsedTime = ((double) (stopTotalTime.tv_sec - startTotalTime.tv_sec)
			+ (stopTotalTime.tv_nsec - startTotalTime.tv_nsec)
					/ (double) 1000000000L);
	printf("CPU used time =%g and application total time=%g \n",cpuUsedTime,totalUsedTime);
	return 0;
}
