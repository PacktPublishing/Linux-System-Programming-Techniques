#include <stdio.h>

int main(void)
{
   #ifdef __STDC_VERSION__
      printf("Standard C version: %ld\n", 
         __STDC_VERSION__);
   #endif
   #ifdef _XOPEN_SOURCE
      printf("XOPEN_SOURCE: %d\n", 
         _XOPEN_SOURCE);
   #endif
   #ifdef _POSIX_C_SOURCE
      printf("POSIX_C_SOURCE: %ld\n", 
         _POSIX_C_SOURCE);
   #endif
   #ifdef _GNU_SOURCE
      printf("GNU_SOURCE: %d\n", 
         _GNU_SOURCE);
   #endif
   #ifdef _BSD_SOURCE
      printf("BSD_SOURCE: %d\n", _BSD_SOURCE);
   #endif
   #ifdef _DEFAULT_SOURCE
      printf("DEFAULT_SOURCE: %d\n", 
         _DEFAULT_SOURCE);
   #endif

   return 0;
}
