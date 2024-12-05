#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ls_command.h"
#include "cat_command.h"

#define MAX_LINE 80
#define MAX_ARGS 10


// 실행 프롬프트
int main(){

    char input[MAX_LINE];
    char *token;
    char *argv[MAX_ARGS];


    while(1){
        // prompt
        printf("myshell> ");

        // read command
        fgets(input, MAX_LINE, stdin);
        printf("%s\n", input);

        // tokenize input
        token = strtok(input, " \n\t");
        int i =0;

        while(token != NULL){
            argv[i++] = token;
            token = strtok(NULL, " \n\t");
        }

        if(argv[0] == NULL){ // empty command
            continue;
        }
        argv[i] = NULL; // 더 이상 argument가 없다는 것을 알려줌

        if (strcmp(argv[0], "exit") == 0){
            printf("Good bye!\n");
            exit(0);
        }
        else if(strcmp(argv[0], "cd") == 0){
            chdir(argv[1]);
        }
        else if(strcmp(argv[0], "pwd") == 0){
            getcwd(input, MAX_LINE);
            printf("%s\n",input);
        }
        else if(strcmp(argv[0], "ls") == 0){
            my_ls();
        }
        else if(strcmp(argv[0], "cat") == 0){
            // you code comes here..  argv[1]이 필요
            my_cat(argv[1]);
        }
        else { // 실행파일이거나 명령어를 잘못 입력했거나의 경우
            if(access(argv[0] , X_OK) == 0){
                pid_t pid = fork();
                // printf("execute %s\n", argv[0]);
                if (pid < 0) { // fork 실패 시
                    perror("fork failed");
                    continue;
                }
                if(pid == 0){
                    execv(argv[0], argv);
                    perror("execv faild\n");
                    exit(1);
                }
                else{
                    wait(NULL);
                }
            }
            else{
                printf("command not found: %s\n", argv[0]);
            }
        }

    }


   return 0;
}