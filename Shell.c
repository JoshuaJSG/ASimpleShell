#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>


#define bufferOf 1024
char *path = NULL;
char *cmndtkn[512];
char pwd[1024];


void introduction(){
  printf("\t********************************\n");
  printf("\t* Shell by Joshua Steele-Gomes *\n");
  printf("\t********************************\n");
}


  int main(int argc, char **argv){
      char commandLine[1000];  //get command line
      introduction();

      char *tokens = strtok(commandLine," ");
      int i = 0;

  while(1){

      printf("My shell>> ");
      if(!fgets(commandLine, 1000, stdin)){  //get the command and place as the first line.
        break;
      }

      if(strcmp(commandLine, "info\n")==0){        // If the command is "info", print the print statement
        printf("COMP2211 Simplified Shell by sc16jsg \n");
      }

      if(strcmp(commandLine, "help\n")==0){        // If the command is "help", print the print statement
        printf("\n\tAvailable commands: \n");
        printf("\tinfo - Infomation about who created the shell\n");
        printf("\texit - Exit from the current shell\n");
        printf("\tpwd -  Print working directory\n");

      }

      if(strcmp(commandLine, "exit\n")==0){        //If the command is exit, break.
          break;
      }

      if(strcmp(commandLine, "pwd\n")==0){         //If the command is "pwd" use function against PWD and print working directory.
        getcwd(pwd, sizeof(pwd));
        printf("current directory: %s\n", pwd);
      }
  }


  }
