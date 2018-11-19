# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>


int rand_num(){
  //because forked processes need a diff seed if done the other way
  int random_data = open("/dev/random", O_RDONLY);
  //malloc
  int * p = (int *)malloc(sizeof(int));
  read(random_data, p, sizeof(p));
  int num = abs(*p);
  //free
  free(p);
  if (close(random_data) < 0){
    printf("ERROR CLOSING FILE");
  };
  while(num>15){
    num = num%20;
    num+=5;
  }
  return num;
}


int main(){
  printf("Parent pid: %i ppid: %i\n", getpid(), getppid());

  int f = fork();
  int time = rand_num();

  if (f == -1) {
    printf("error");
  //parent forks again to make two children
  } else if(f) {
    printf("Parent of %i pid: %i ppid: %i\n\n", f, getpid(), getppid());
    f = fork();
  }

  //for the child process
  if (f == 0){
    printf("I am a child pid: %i ppid: %i\n", getpid(), getppid());
    sleep(time);
    return time;
  }

  //parent process stuff
  int status;
  int sleepy_child = wait(&status);
  int seconds = WEXITSTATUS(status);
  printf("My sleepy child %d slept for %d seconds\n", sleepy_child, seconds);
  printf("Parent process is done!\n");

  return 0;
}
