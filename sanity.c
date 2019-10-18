
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int  k, n, id, retime, rutime, stime;

  n = atoi(argv[1]);
  id = 0;
  for ( k = 0; k < 3*n; k++ ) {
    id = fork ();
    if ( id > 0 ) {  //parent
      wait();
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
    	printf(0, "CPU-Bound %d\n",id);
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
    	printf(0, "S-Bound%d\n",id);
      }
      if (k%3==2)
      {
    	for (int i = 0; i < 100; ++i)
    	{
    	
    		sleep(1);
    	}
    	printf(0, "IO-Bound%d\n",id);
      }
      break;
    }
  }
  wait2(&retime,&rutime,&stime);
  printf(0, "%d %d %d\n", retime,rutime,stime);
  exit();
}