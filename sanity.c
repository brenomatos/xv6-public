
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "defs.h"

int
main(int argc, char *argv[])
{
  int  k, n, id, retime, rutime, stime;

  n = atoi ( argv[1] );
  // if(argc < 2 )
  //   n = 1;       //default value
  // else
  //   n = atoi ( argv[1] ); //from command line
  // if ( n < 0 || n > 20 )
  //   n = 2;
  id = 0;
  for ( k = 0; k < 3*n; k++ ) {
    id = fork ();
    if ( id > 0 ) {  //parent
      printf(1, "Parent %d creating child  %d\n", getpid(), id );
     // wait ();
    } else {   // child
      printf(1, "Child %d created\n",getpid() );
    if (id%3==0)
    {
    	for (int i = 0; i < 100; ++i)
    	{
    		for (int j = 0; j < 1000000; ++j)
    		{
    			
    		}
    	}
    	printf(1, "CPU-Bound %d\n",id );
    	wait2(&retime,&rutime,&stime);
    	printf(1, "%d %d %d\n", retime,rutime,stime);
    	exit();
    }
    if (id%3==1)
    {
    	for (int i = 0; i < 100; ++i)
    	{
    		for (int j = 0; j < 1000000; ++j)
    		{
    			
    		}
    		yield();
    	}
    	printf(1, "S-Bound%d\n",id );
    	wait2(&retime,&rutime,&stime);
    	printf(1, "%d %d %d\n", retime,rutime,stime);
    	exit();
    }
    if (id%3==2)
    {
    	for (int i = 0; i < 100; ++i)
    	{
    	
    		sleep(1);
    	}
    	printf(1, "IO-Bound%d\n",id );
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