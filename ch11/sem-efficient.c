#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void *add(void *arg);
long long int i = 0;
sem_t i_sem;

int main(void)
{
   pthread_attr_t threadattr;
   pthread_attr_init(&threadattr);
   pthread_t tid_add1, tid_add2, tid_add3, 
     tid_add4, tid_add5;

   if ( (sem_init(&i_sem, 0, 1)) == -1 )
   {
      perror("Initialize semaphore");
      return 1;
   }
   pthread_create(&tid_add1, &threadattr, 
      add, NULL);
   pthread_create(&tid_add2, &threadattr, 
      add, NULL);
   pthread_create(&tid_add3, &threadattr, 
      add, NULL);
   pthread_create(&tid_add4, &threadattr, 
      add, NULL);
   pthread_create(&tid_add5, &threadattr, 
      add, NULL);

   pthread_join(tid_add1, NULL);
   pthread_join(tid_add2, NULL);
   pthread_join(tid_add3, NULL);
   pthread_join(tid_add4, NULL);
   pthread_join(tid_add5, NULL);

   printf("Sum is %lld\n", i);
   if ( (sem_destroy(&i_sem)) == -1 )
   {
      perror("Destory semaphore");
      return 1;
   }
   return 0;
}

void *add(void *arg)
{
   long long int j;
   for (j = 1; j < 1000000000; j++)
   {
      /* we don't do any work in the loop, we wait
       * until it's ready to update i */
   }
   sem_wait(&i_sem);
   i = i + j;
   sem_post(&i_sem);
   return NULL;
}
