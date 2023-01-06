#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

int main() {
    printf("Hello!\n");
    struct taskNode t;
    t.dateDue = "12/24/2023";
    printf( "struct t's due date is %s\n", t.dateDue );
    
    // onload array with tasks from csv if applicable
    FILE* f = fopen( "data.csv", "rw" );



    struct taskNode* tasks = (struct taskNode*)malloc(sizeof(taskNode));
    tasks[0] = t;
    tasks[0].dateDue = "01/23/2023";
    printf( "struct t's due date is %s\n", t.dateDue );
    printf( "struct t's due date is %s\n", tasks[0].dateDue );


    free(tasks);
    return 0;
} 