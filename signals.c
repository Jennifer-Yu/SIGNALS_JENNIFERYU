//Jennifer Yu
//11-10-16

/*
DONE - Runs constantly inside a forever while loop.
DONE - Print out the process' PID inside the loop.
DONE - Use the sleep(1) function to have the program wait 1 second between inner loop iterations.
DONE - Catch the following signals
    - SIGINT
        - Before exiting, append a message to a file noting that the program exited due to SIGINT
        - To make your program quit, look up the exit function.
    - SIGUSR1
        - Print out the PID of the parent process.
        - Should not cause the program to exit.
*/

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

static void sighandler(int signo) {

  if (signo == SIGINT) { //signal 2

    umask(0000); //default umask

    int fd = open("bubtea.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
    char ret[] = "program exited due to SIGINT!!! YAAAS IT WORKS";
    write(fd, ret, sizeof(ret));

    close(fd);
    exit(0); //successful program termination [exit(1) --> unsuccessful]

  }

  else if (signo == SIGUSR1) { //signal 10
    printf("PPID: %d\n", getppid()); //parent ppid
  }

}

int main() {

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    printf("PID: %d\n", getpid());
    sleep(1);
  }

  return 0;

}