#include <stdio.h>
#include "heapsort.h"

int main() {
    printf("Hello!\n");
    struct taskNode t;
    t.dateDue = "12/24/2023";
    printf( "struct t's due date is %s\n", t.dateDue );
    
    
    struct taskNode *tasks = (struct taskNode*)malloc(sizeof(struct taskNode));
    tasks[0] = t;
    tasks[0].dateDue = "01/23/2023";
    printf( "struct t's due date is %s\n", t.dateDue );
    printf( "struct t's due date is %s\n", tasks[0].dateDue );


    free(tasks);
    return 0;
} 