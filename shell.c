# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "strep.h"

int main(int argc, char * argv[]){
  char command[100];
  printf("Enter Command:\n");
  fgets(command, 100, stdin);
  char ** args = parse_args(command);
  printer( args );
  execvp(args[0], args);
  //executing the command (args[0]) with the flags (args)
  printf("ARGS[0]: %s\n", args[0]);
  // char * ans = strcat("/bin/", args[0]);
  free(args);
  printf("ERROR: %s\n", strerror(errno));
  return 0;
}
