#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[])
{
    struct stat filestat;
    struct passwd *userinfo;
    struct group *groupinfo;
    if ( argc != 2 )
    {
        fprintf(stderr, "Usage: %s <file>\n", 
            argv[0]);
        return 1;
    }
    if ( stat(argv[1], &filestat) == -1 )
    {
        fprintf(stderr, "Can't read file %s: %s\n", 
            argv[1], strerror(errno));
        return errno;
    }
    if ( (userinfo = getpwuid(filestat.st_uid)) == 
        NULL )
    {
        perror("Can't get username");
        return errno;
    }
    if ( (groupinfo = getgrgid(filestat.st_gid)) == 
        NULL )
    {
        perror("Can't get groupname");
        return errno;
    }
    printf("Inode: %lu\n", filestat.st_ino);
    printf("Size: %zd\n", filestat.st_size);
    printf("Links: %lu\n", filestat.st_nlink);
    printf("Owner: %d (%s)\n", filestat.st_uid, 
        userinfo->pw_name);
    printf("Group: %d (%s)\n", filestat.st_gid, 
        groupinfo->gr_name);
    printf("File mode: %o\n", filestat.st_mode);
    return 0;
}
