#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

void *isprime(void *arg);
void *progress(void *arg);
pthread_mutex_t lock;
pthread_cond_t ready;
pthread_t primeid = 0;

int main(int argc, char *argv[])
{
   long long number1;
   long long number2;
   pthread_t tid_prime1;
   pthread_t tid_prime2;
   pthread_t tid_progress;
   pthread_attr_t threadattr;
   void *prime1Return;
   void *prime2Return;

   if ( (pthread_mutex_init(&lock, NULL)) != 0 )
   {
      fprintf(stderr, 
         "Couldn't initialize mutex\n");
      return 1;
   }

   if ( (pthread_cond_init(&ready, NULL)) != 0 )
   {
      fprintf(stderr, 
        "Couldn't initialize condition variable\n");
      return 1;
   }

   if ( argc != 3 )
   {
      fprintf(stderr, "Please supply two numbers.\n"
         "Example: %s 9 7\n", argv[0]);
      return 1;
   }
   number1 = atoll(argv[1]);
   number2 = atoll(argv[2]);
   pthread_attr_init(&threadattr);
   pthread_create(&tid_progress, &threadattr, 
      progress, NULL);  
   pthread_detach(tid_progress);
   pthread_create(&tid_prime1, &threadattr, 
      isprime, &number1);
   pthread_create(&tid_prime2, &threadattr, 
      isprime, &number2);

   pthread_mutex_lock(&lock);
   for (int i = 0; i < 2; i++)
   {
      while (primeid == 0)
         pthread_cond_wait(&ready, &lock);
      if (primeid == tid_prime1)
      {
         pthread_join(tid_prime1, &prime1Return);
         if (  (uintptr_t)prime1Return == 1 )
            printf("\n%lld is a prime number\n", 
               number1);
         else
            printf("\n%lld is not a prime number\n", 
               number1);
         primeid = 0;
      }
      else
      {
         pthread_join(tid_prime2, &prime2Return);   
         if ( (uintptr_t)prime2Return == 1 )
            printf("\n%lld is a prime number\n", 
               number2);
         else
            printf("\n%lld is not a prime number\n", 
               number2);
         primeid = 0;
      }
   }
   pthread_mutex_unlock(&lock);

   pthread_attr_destroy(&threadattr);
   if ( pthread_cancel(tid_progress) != 0 )
      fprintf(stderr, 
         "Couldn't cancel progress thread\n");
  
   return 0;
}

void *isprime(void *arg)
{
   long long int number = *((long long*)arg);
   long long int j;
   int prime = 1;
    
   for(j=2; j<number; j++)
   {
      if(number%j == 0)
         prime = 0;
   }
   pthread_mutex_lock(&lock);
   primeid = pthread_self();
   pthread_cond_signal(&ready);
   pthread_mutex_unlock(&lock);
   if(prime == 1)
      return (void*)1;
   else
      return (void*)0;
}

void *progress(void *arg)
{
   while(1)
   {
      sleep(1);
      printf(".");
      fflush(stdout);
   }
   return NULL;
}
