#include <stdio.h>
#include "heapsort.h"

int main() {
    printf("Hello!\n");
    struct taskNode t;
    t.dateDue = "12/24/2023";
    printf( "struct t's due date is %s\n", t.dateDue );
    

    
    struct taskNode *tasks = (struct taskNode*)malloc(sizeof(taskNode));
    tasks[0] = t;
    printf("dateDue of tasks[0] = %s\n", tasks[0].dateDue );



    free(tasks);

    return 0;
} 