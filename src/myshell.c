#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

        if(argv[0] == NULL){
            continue;
        }
        argv[i] = NULL; // 더 이상 argument가 없다는 것을 알려줌

        if (strcmp(argv[0], "exit") == 0){
            printf("Good bye!\n");
            exit(0);
        }

    }


   
}