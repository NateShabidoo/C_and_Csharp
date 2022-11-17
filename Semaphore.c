/*
 * File: semaphore.c
 * This creates a parent and child process and uses semaphore to make child process wait for parent process to complete first
 */

#define _POSIX_C_SOURCE 200112L
#define _ISOC99_SOURCE
#define _XOPEN_SOURCE 600

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>

int main() {
  /* unlink semophare first before creation */
	sem_unlink("/CSCI435sem1");

	sem_t	*my_sem1 = sem_open("/CSCI435sem1", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
	if(my_sem1 == SEM_FAILED) {
		printf("sem_open failed: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

  pid_t x = fork();
  if(x == 0) { // this is child process
    sem_wait(my_sem1); //this blocks child process as it waits for my_sem1 to become '1'
    printf("\tI am child process and its my turn to do something\n");
    for(int w = 0; w < 2147483647; ++w)
    ;
    printf("\tchild process finishes\n");
    exit(EXIT_SUCCESS);
  }
  else if(x > 0) { // this is parent process
    printf("I am parent process and I do something first\n");
    for(int w = 0; w < 2147483647; ++w)
    ;
    sem_post(my_sem1); // this sets my_sem1 to '0' so child can acquire
    wait(NULL);
    printf("parent process prepares to leave\n");
    exit(EXIT_SUCCESS);
  }
}
