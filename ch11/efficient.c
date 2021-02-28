#include <stdio.h>
#include <pthread.h>

void *add(void *arg);
long long int i = 0;
pthread_mutex_t i_mutex;

int main(void)
{
   pthread_attr_t threadattr;
   pthread_attr_init(&threadattr);
   pthread_t tid_add1, tid_add2, tid_add3, 
     tid_add4, tid_add5;

   if ( (pthread_mutex_init(&i_mutex, NULL)) != 0 )
   {
      fprintf(stderr, 
         "Couldn't initialize mutex\n");
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
   if ( (pthread_mutex_destroy(&i_mutex)) != 0 )
   {
      fprintf(stderr, "Couldn't destroy mutex\n");
      return 1;
   }
   return 0;
}

void *add(void *arg)
{
   long long int j = 1;
   while(j < 1000000000)
   {
      j = j + 1;
   }

   pthread_mutex_lock(&i_mutex);
   i = i + j;
   pthread_mutex_unlock(&i_mutex);
   return NULL;
}
