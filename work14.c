#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static void signal_catcher(int signal) {
   if (signal == SIGINT) {
      //apending message to file noting the program exited...
      int in = open("exit.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
      char * message = "Program exited due to SIGINT.\n";
      int w = write(in, message, strlen(message));
      close(in);

      //exit with "0" as the status means program successfully terminated
      //without error
      exit(0);
   }

   if (signal == SIGUSR1) {
      //getppid() returns current process parent pid
      printf("PID of Parent Process: %d\n", getppid());
      //program doesn't exit
      //test using kill -10 pid (10 is sigusr1)
   }
}

int main() {
   signal(SIGINT, signal_catcher);
   signal(SIGUSR1, signal_catcher);
   //1==1 is always true
   while (1 == 1) {
      //getpid() returns current process pid
      printf("PID of Process:%d\n", getpid());
      //1 second between loop iterations
      sleep(1);
   }
   return 0;
}
