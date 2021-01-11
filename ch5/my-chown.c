#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
   struct passwd *user; /* struct for getpwnam */
   struct group *grp; /* struct for getgrnam */
   char *username = { 0 }; /* extracted username */
   char *groupname = { 0 }; /*extracted groupname*/
   unsigned int uid, gid; /* extracted UID/GID */

   /* Check that the user supplied two arguments 
      (filename and user or user:group) */
   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s [user][:group]" 
         " [path]\n", argv[0]);
      return 1;
   }

   /* Extract username and groupname */
   username = strtok(argv[1], ":");
   groupname = strtok(NULL, ":");
    
   if ( (user = getpwnam(username)) == NULL )
   {
      fprintf(stderr, "Invalid username\n");
      return 1;
   }
   uid = user->pw_uid; /* get the UID */

   if (groupname != NULL) /* if we typed a group */
   {
      if ( (grp = getgrnam(groupname)) == NULL )
      {
         fprintf(stderr, "Invalid groupname\n");
         return 1;
      }
      gid = grp->gr_gid; /* get the GID */
   }
   else
   {
      /* if no group is specifed, -1 won't change 
         it (man 2 chown) */
      gid = -1;
   }
    
   /* update user/group (argv[2] is the filename)*/
   if ( chown(argv[2], uid, gid) == -1 )
   {
      perror("Can't change owner/group");
      return 1;
   }
   return 0;
}
