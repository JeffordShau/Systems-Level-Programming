#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int ppid = getpid();
  printf("Parent Process PID: %d\n", ppid);
  // forks the parent process to create child process
  int forkVal = fork();
  if (forkVal < 0) {
    printf("Creation of child process was unsuccessful\n");
    exit(0);
  }
  // parent process
  if (forkVal != 0) {
    int status;
    printf("Waiting for child process %d to finish\n", forkVal);
    wait(&status);
    if (WIFEXITED(status)) {
      int retVal = WEXITSTATUS(status);
      printf("Parent process confirms child process %d finished, Slept %d secs\n", forkVal, retVal);
    }
    printf("Parent process %d finished.\n", getpid());
    exit(0);
  }
  // forks the child process to create another child
  if (forkVal == 0) {
    int forkVal2 = fork();
    if (forkVal2 < 0) {
      printf("Creation of child process was unsuccessful\n");
      exit(0);
    }
    srand(getpid());
    int x = rand() % 4 + 2;
    printf("Child PID: %d, Sleep %d sec\n", getpid(), x);
    sleep(x);
    printf("Child process: %d finished, Parent process: %d\n", getpid(), getppid());
    return x;
  }
}
