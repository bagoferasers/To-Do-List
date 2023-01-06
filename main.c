#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "heapsort.h"

int main() {

    // find file path and open file
    char wd[256] = __FILE__;
    char newFilePath[256];
    for( int i = 0; i < (strlen(wd) - 6); i++ ){
        newFilePath[i] = wd[i];
    }
    strcat(newFilePath, "\\data.csv");
    FILE* f = fopen( newFilePath, "r+" );

    // if can't find file, output and return
    if(f == NULL) {
        printf( "Can't open file\n" );
        return -1;
    }

    // else begin program
    else {
        struct taskNode* tasks = (struct taskNode*)malloc(sizeof(taskNode));
        
        

        free(tasks);
    }
    
    fclose(f);
    return 0;
} 