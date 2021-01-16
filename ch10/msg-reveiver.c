#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   int md; /* msg queue descriptor */
   char *buffer;
   struct mq_attr msgattr;
   md = mq_open("/my_queue", O_RDONLY);
   if (md == -1 )
   {
      perror("Open message queue");
      return 1;
   }
   if ( (mq_getattr(md, &msgattr)) == -1 )
   {
      perror("Get message attribute");
      return 1;
   }
   buffer = calloc(msgattr.mq_msgsize, 
      sizeof(char));
   if (buffer == NULL)
   {
      fprintf(stderr, "Couldn't allocate memory");
      return 1;
   }
   printf("%ld messages in queue\n", 
      msgattr.mq_curmsgs);
   for (int i = 0; i<msgattr.mq_curmsgs; i++)
   {
      if ( (mq_receive(md, buffer, 
      msgattr.mq_msgsize, NULL)) == -1 )
      {
         perror("Message receive");
         return 1;
      }
      printf("%s\n", buffer);
      memset(buffer, '\0', msgattr.mq_msgsize);
   }

   free(buffer);
   mq_close(md);
   mq_unlink("/my_queue");
   return 0;
}
