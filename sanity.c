
#include "types.h"
#include "stat.h" //tiramos mas sei la
#include "user.h"
#include "fcntl.h" //tiramos mas sei la2

// #include "stdio.h"// #include "stdlib.h"
// #include "defs.h"


int
main(int argc, char *argv[])
{
  int  k, n, id, retime, rutime, stime;

  n =  atoi(argv[1]);
  id = 0;
  for ( k = 0; k < 3*n; k++ ) {
    id = fork ();
    if ( id > 0 ) {  //parent
      // printf(1, "Parent %d creating child  %d\n", getpid(), id - n + 1);
    	wait ();
    } else {   // child
      printf(1, "Process %d created\n",k);
    if (k%3==0)
    {
    	for (int i = 0; i < 100; ++i)
    	{
    		for (int j = 0; j < 1000000; ++j)
    		{
    			
    		}
    	}
    	printf(1, "CPU-Bound %d\n",id);
    	wait2(&retime,&rutime,&stime);
    	printf(1, "%d %d %d\n", retime,rutime,stime);
    	exit();
    }
    if (k%3==1)
    {
    	for (int i = 0; i < 100; ++i)
    	{
    		for (int j = 0; j < 1000000; ++j)
    		{
    			
    		}
    		yield();
    	}
    	printf(1, "S-Bound%d\n",id);
    	wait2(&retime,&rutime,&stime);
    	printf(1, "%d %d %d\n", retime,rutime,stime);
    	exit();
    }
    if (k%3==2)
    {
    	for (int i = 0; i < 100; ++i)
    	{
    	
    		sleep(1);
    	}
    	printf(1, "IO-Bound%d\n",id);
    	wait2(&retime,&rutime,&stime);
    	printf(1, "%d %d %d\n", retime,rutime,stime);
    	exit();
    }
      exit();
      break;
    }
  }
  exit();
}