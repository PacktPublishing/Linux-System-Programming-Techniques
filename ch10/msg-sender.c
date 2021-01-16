#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#define MAX_MSG_SIZE 2048

int main(int argc, char *argv[])
{
   int md; /* msg queue descriptor */
   /* attributes for the message queue */
   struct mq_attr msgattr;
   msgattr.mq_maxmsg = 10;
   msgattr.mq_msgsize = MAX_MSG_SIZE;

   if ( argc != 2)
   {
      fprintf(stderr, "Usage: %s 'my message'\n",
         argv[0]);
      return 1;
   }
   md = mq_open("/my_queue", O_CREAT|O_RDWR, 0644, 
      &msgattr); 
   if ( md == -1 )
   {
      perror("Creating message queue");
      return 1;
   }
   if ( (mq_send(md, argv[1], strlen(argv[1]), 1))
      == -1 )
   {
      perror("Message queue send");
      return 1;
   }
   mq_close(md);
   return 0;
}
