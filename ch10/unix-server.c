#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#define MAXLEN 128

void cleanUp(int signum);
const char sockname[] = "/tmp/my_1st_socket";
int connfd;
int datafd;

int main(void)
{
   int ret;
   struct sockaddr_un addr;
   char buffer[MAXLEN];
   struct sigaction action;
   /* prepare for sigaction */
   action.sa_handler = cleanUp;
   sigfillset(&action.sa_mask);
   action.sa_flags = SA_RESTART;
   /* register the signals we want to handle */
   sigaction(SIGTERM, &action, NULL);
   sigaction(SIGINT, &action, NULL);
   sigaction(SIGQUIT, &action, NULL);
   sigaction(SIGABRT, &action, NULL);
   sigaction(SIGPIPE, &action, NULL);

   /* create socket file descriptor */
   connfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
   if ( connfd == -1 )
   {
      perror("Create socket failed");
      return 1;
   }
   /* set address family and socket path */
   addr.sun_family = AF_UNIX;
   strcpy(addr.sun_path, sockname);
   /* bind the socket (we must cast our sockaddr_un
    * to sockaddr) */
   if ( (bind(connfd, (const struct sockaddr*)&addr, 
      sizeof(struct sockaddr_un))) == -1 )
   {
      perror("Binding socket failed");
      return 1;
   }
   /* prepare for accepting connections */
   if ( (listen(connfd, 20)) == -1 )
   {
      perror("Listen error");
      return 1;
   }
   /* accept connection and create new file desc */
   datafd = accept(connfd, NULL, NULL);
   if (datafd == -1 )
   {
      perror("Accept error");
      return 1;
   }
   printf("Client connected\n");
   while(1) /* main loop */
   {
      while(1) /* receive message, line by line */
      {
         ret = read(datafd, buffer, MAXLEN);
         if ( ret == -1 )
         {
            perror("Error reading line");
            cleanUp(1);
         }
         else if ( ret == 0 )
         {
            printf("Client disconnected\n");
            cleanUp(1);
         }
         else
         {
            printf("Message: %s\n", buffer);
            break;
         }
      }
   /* write a confirmation message */
   write(datafd, "Message received\n", 18);
   }
   return 0;
}

void cleanUp(int signum)
{
   printf("Quitting and cleaning up\n");
   close(connfd);
   close(datafd);
   unlink(sockname);
   exit(0);
}
