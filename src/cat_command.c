#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "cat_command.h"

void my_cat(char *filename){
    // printf("%s\n",filename);
    int fd = open(filename, O_RDONLY);
    char buffer[1024];
    ssize_t bytes = read(fd, buffer, sizeof(buffer));

    if(fd == -1){
        perror("my open: ");
        return;
    }
    
    printf("%s\n",buffer);

    close(fd);
}