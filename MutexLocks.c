// lock2.c -- creating and terminating threads

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n;

int m1 = 2, m2 = 4;
int m3 = 3;

// below is new
pthread_mutex_t lock;

// below is new mutex lock initialization
int pthread_mutex_init(
pthread_mutex_t *restrict mutex,
const pthread_mutexattr_t *restrict attr);
// end of mutex lock initialize


void * run(void * ptr){
  int t = *(int *)ptr;
  int i;
  printf("Thread with t=%d has requested the lock\n", t);
  //now it requests mutex lock
  pthread_mutex_lock(&lock);

  printf("Thread with t=%d has obtained the lock\n", t);
  sleep( rand()%t );
  i = n;
  sleep( rand()%t );
  i += 1;
  sleep( rand()%t );
  n = i;
  //now it releases mutex lock
  pthread_mutex_unlock(&lock);
  printf("Thread with t=%d has released the lock\n", t);
  pthread_exit(NULL);
}

int main(){
  pthread_t thr1, thr2, thr3;

  srand( getpid() );
  
  n = 0;
  
  printf("Creating threads\n\n");

  pthread_create(&thr1, NULL, run, &m1);
  pthread_create(&thr2, NULL, run, &m2);
  pthread_create(&thr3, NULL, run, &m3);

  printf("Threads have been created\n");

  pthread_join(thr3, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr1, NULL);
  
  printf("n = %d\n", n);
}
