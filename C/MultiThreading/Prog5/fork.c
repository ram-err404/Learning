/****************************************************************************************
 * Fork system call use for creates a new process, which is called child 
 * process, which runs concurrently with process (which process called 
 * system call fork) and this process is called parent process. After a
 * new child process created, both processes will execute the next
 * instruction following the fork() system call. A child process uses
 * the same pc(program counter), same CPU registers, same open files 
 * which use in the parent process.
 * It takes no parameters and returns an integer value. Below are 
 * different values returned by fork().
 *
 * Negative Value: creation of a child process was unsuccessful.
 * Zero: Returned to the newly created child process.
 * Positive value: Returned to parent or caller. The value contains process
 * 			ID of newly created child process.
 *
 * Ex: 3 concurrent call of fork.
 *
 * fork ();   // Line 1
 * fork ();   // Line 2
 * fork ();   // Line 3
 *
 *		  	   L1 	      		// There will be 1 child process 
 *    		/     \ 	    	// created by line 1.
 *	       L2      L2    		// There will be 2 child processes
 *	      /  \    /  \   		//  created by line 2
 *	     L3  L3  L3  L3  		// There will be 4 child processes 
 *					// created by line 3
 *****************************************************************************************/

#include	<stdio.h>
#include	<pthread.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>

int i = 0;	/*Global variables will get different addresses in fork child and parent process*/
			/* Memory spaces duplicated and have different reference in every process.*/

void doSomething(char *name)
{
	int NUM_TIMES = 5;
	for (; i<NUM_TIMES; i++) {
		sleep(rand() % 4);
		printf("Pass:%d for %s \n", i, name);
	}
}

int main() 
{
	pid_t pid;
	printf("Main pid:%d\n", (int)getpid());
	
	pid = fork();
	printf("fork returned pid:%d\n", (int)pid);

	if(pid < 0) {
		perror("Failed to fork\n");
	} 
	if (pid == 0) {
		printf("I'm child with pid:%d\n", (int)getpid());
		doSomething("Child");
		printf("Child exiting... \n");
		exit(0);
	} 
	
	/* We must be parent here*/
	printf("I'm parent with pid:%d\n", (int)getpid());
	doSomething("Parent");
	wait(NULL);
	printf("Parent ending...\n");
	
	return 0;
}
