#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
   char rxbuf[1];
   char txbuf[3];
   int master; /* for the pts master fd */
   int c; /* to catch read's return value */

   master = posix_openpt(O_RDWR);
   grantpt(master);
   unlockpt(master);
   printf("Slave: %s\n", ptsname(master));

   while(1) /* main loop */
   {
      /* read from the master file descriptor */
      c = read(master, rxbuf, 1);
      if (c == 1)
      {
         /* convert carriage return to '\n\r' */
         if (rxbuf[0] == '\r')
         {
            printf("\n\r"); /* on master */
            sprintf(txbuf, "\n\r"); /* on slave */
         }
         else
         { 
            printf("%c", rxbuf[0]); 
            sprintf(txbuf, "%c", rxbuf[0]);
         }
         fflush(stdout);
         write(master, txbuf, strlen(txbuf));
      }
      else /* if c is not 1, it has disconnected */
      {
         printf("Disconnected\n\r");
         return 0;
      } 
   }
   return 0;
}
