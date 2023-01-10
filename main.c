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
        //and replace "10" with the #
        struct taskNode* tasks = malloc( 10 * sizeof( struct taskNode ) );

        //testing tasknode inserts
        struct taskNode t1 = buildNode(1,1,1,"bear task","descripty description", "12/12/1220");
        insertNode( tasks, t1 );
        struct taskNode t2 = buildNode(2,2,2,"my task","i will not be describing this", "01/01/1220");
        insertNode( tasks, t2 );
        
        //printing tasks
        int j = 0;
        while(  tasks[ j ].dateDue != NULL && isalpha(tasks[ j ].name[0] ) ){
            printf("%s is %s\n", tasks[ j ].name, tasks[ j ].description);
            j++;
        }

        free(tasks);
    }
    fclose( f );
    return 0;
}