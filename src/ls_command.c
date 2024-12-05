#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include "ls_command.h"

void my_ls(void){
    DIR *dir;
    struct dirent *entry;

    dir = opendir("."); // 현재 디렉토리에 있는 파일들만 보여주도록 짜봄
    if(dir == NULL){ // error 발생한 경우
        perror("opendir");
        return; 
    }
    else{
        while((entry = readdir(dir)) != NULL ){
            if(entry->d_type == DT_DIR){
                printf("%s/\n", entry->d_name); // directory임을 표시하기 위해 if문 추가
            }
            else{
                printf("%s\n", entry->d_name); // 파일이름 찍어줌
            }
        }
    }
    closedir(dir);
}