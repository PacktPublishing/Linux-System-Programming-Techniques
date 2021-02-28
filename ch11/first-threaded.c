#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *isprime(void *arg);
void *progress(void *arg);

int main(int argc, char *argv[])
{
   long long number1;
   long long number2;
   pthread_t tid_prime1;
   pthread_t tid_prime2;
   pthread_t tid_progress;
   pthread_attr_t threadattr;
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
   pthread_join(tid_prime1, NULL);
   pthread_join(tid_prime2, NULL);
   pthread_attr_destroy(&threadattr);
   if ( pthread_cancel(tid_progress) != 0 )
      fprintf(stderr, 
         "Couldn't cancel progress thread\n");
   printf("Done!\n");
   return 0;
}

void *isprime(void *arg)
{
   long long int number = *((long long*)arg);
   long long int j;
   int prime = 1;
    
   /* Test if the number is divisible, starting 
    * from 2 */
   for(j=2; j<number; j++)
   {
      /* Use the modulo operator to test if the 
       * number is evenly divisible, i.e., a 
       * prime number */
      if(number%j == 0)
      {
         prime = 0;
      }
   }
   if(prime == 1)
   {
      printf("\n%lld is a prime number\n", 
         number);
      return NULL;
   }
   else
   {
      printf("\n%lld is not a prime number\n", 
         number);
      return NULL;
   }
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
