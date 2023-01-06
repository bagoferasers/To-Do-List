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

        //need to find out how many tasks are in tasknode with input from csv
        struct taskNode tasks[ 10 ];

        struct taskNode t1;
        t1.priority = 5;
        t1.timeInMinutes = 20;
        t1.timeInHours = 0;
        t1.name = "Task 1";
        t1.description = "This is the description";
        t1.dateDue = "12/25/2023";

        struct taskNode t2;
        t2.priority = 5;
        t2.timeInMinutes = 20;
        t2.timeInHours = 0;
        t2.name = "Task 2";
        t2.description = "This is the description";
        t2.dateDue = "04/24/2024";
    
        tasks[0] = t1;
        tasks[1] = t2;

        printf("Printing due dates:\n");
        int j = 0;
        while(1){
            if(tasks[j].name == NULL)
                break;
            else{
                printf("\ttasks[%d].dateDue = %s\n", j, tasks[j].dateDue);
                j++;
            }
        }
        printf("number of tasks is %d\n", j);

    }


    fclose(f);
    return 0;
}