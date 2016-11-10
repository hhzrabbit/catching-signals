#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    umask(0000);
    int fd = open("info.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char msg[] = "exited due to SIGINT signal\n";
    write(fd, msg, sizeof(msg));
    close(fd);
    exit(0);
  }
  else if (signo == 10)
    printf("parent pid: %d\n", getppid());
}


int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
    
  while (1){
    printf("pid: %d\n", getpid());
     sleep(1);
  }

  return 0;
}
