#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "heapsort.h"

int main( ) {

    // find file path and open file
    FILE* f = fopen( "data.csv", "r+" );

    // if can't find file, output and return
    if( f == NULL ) {
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
        tasks[ 0 ] = t1;

        //tasks[ 3 ] = buildNode(1,1,1,"bear task","descripty description", "12/12/1220");


        printf( "Printing tasks:\n" );
        int j = 0;
        while( isalpha(tasks[ j ].name[0]) ){
            j++;
        }
        printf( "number of tasks is %d\n", j );
    }


    fclose( f );
    return 0;
}