#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   /* Using getenv() to fetch env. variables */
   printf("Your username is %s\n", getenv("USER"));
   printf("Your home directory is %s\n", 
      getenv("HOME"));
   printf("Your preferred editor is %s\n", 
      getenv("EDITOR"));
   printf("Your shell is %s\n", getenv("SHELL"));

   /* Check if the current terminal support colors*/
   if ( strstr(getenv("TERM"), "256color")  )
   {
      /* Color the output with \033 + colorcode */
      printf("\033[0;31mYour \033[0;32mterminal "
         "\033[0;35msupport "
         "\033[0;33mcolors\033[0m\n");
   }
   else
   {
      printf("Your terminal doesn't support" 
         " colors\n");
   }
   return 0;
}
