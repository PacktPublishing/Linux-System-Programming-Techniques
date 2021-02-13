#include <stdio.h>
#include <pthread.h>

void *add(void *arg);
long long int i = 0;

int main(void)
{
   pthread_attr_t threadattr;
   pthread_attr_init(&threadattr);
   pthread_t tid_add1, tid_add2, tid_add3, 
     tid_add4, tid_add5;

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
   return 0;
}

void *add(void *arg)
{
   for (long long int j = 1; j <= 1000000000; j++)
   {
      i = i + 1;
   }
   return NULL;
}
