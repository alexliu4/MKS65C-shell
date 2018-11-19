#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int flags = 0;

int counter(char * line){
  int i, count;
  for (i = 0, count = 0; line[i]; i++){
    count += (line[i] == ' ');
  }
  return count;
}

// char ** parse_args( char * line ) {
//     char ** pArray = malloc(sizeof(char *) * 6);
//     char * str = line;
//     for (int i = 0; i < 6; i++) {
//     *(pArray + i) = strsep(&str , " ");
//     }
//     return pArray;
// }

char ** parse_args( char * line ){
  flags = counter(line) + 1;
  char ** arr = (char **) malloc(sizeof(char *) * flags);
  char *str = line;
  //printf("%d\n", flags);
  for (int i = 0; i <= flags; i++){
    // printf("DOING STRSEP [%s]\n", strsep( &str, " " ));
    // printf("The Addition:%s\n", str);
    *(arr + i) = strsep( &str, " " );
    //printf("[%s]\n", str);
  }
  return arr;
}

void printer(char ** line){
  int i = 0;
  while (i < flags){
    printf("The %dth element: %s\n",i , line[i]);
    i++;
  }
}

int main(int argc, char * argv[]){
    char command[100] = "ls -a -l";
    // printf("Type in command: ");
    // fgets(command, 9, stdin);
    // scanf("%s", command);
    // printf("%s\n", command);
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
