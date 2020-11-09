#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void  childTask() {
  char name[10];
  printf("\nPlease enter your name : ");
  scanf("%s", name);
  printf("Your name is : %s ", name);
  printf("\n");
}

void parentTask() {
  printf("\nJob is done. \n");
}

int main(int argc, char *argv[]) {
  int check =4 ;
  for(int i = 1; i < 5; i++) {
    pid_t pid = fork();

    if(pid == 0) {
      printf("Student %d", i);
      childTask();
      exit(0);
    }
    else  {
      printf("\n");
      wait(NULL);
      if(check==i)
      parentTask();
    }
  }
 // parentTask();

  return EXIT_SUCCESS;
}
