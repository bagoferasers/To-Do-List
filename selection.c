#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#include "taskNode.h"

void showAllTasks( ) 
{
    //show all tasks
    printNodes( 0 );
    printf("\n");
    //while selection
    int selection = -1;
    while( selection != 0 ) 
    {
        printf( "1 - Select task.\n" );
        printf( "0 - Go back.\n" );
        printf("--------------------------------\n");
        printf("Select number : ");

        scanf( "%d", &selection );

        switch( selection ) 
        {
            case 1:
                selectTask( );
                break;
            case 0:
                printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        }
    }
}

void selectTask( ) 
{
    printf("Which task would you like to see?\n");
    int selectedTask = -1;
    scanf("%d", &selectedTask);
    printf("selected Task = %d\n", selectedTask);
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    printf("%s ( priority %d ) is due %s\n%s\n %dh %dm\n\n", tasks[selectedTask].name, tasks[selectedTask].priority, 
            tasks[selectedTask].dateDue, tasks[selectedTask].description, tasks[selectedTask].timeInHours, tasks[selectedTask].timeInMinutes );
    int selection = -1;
    printf("1 - Complete task.\n");
    printf("0 - Go back.\n");
    scanf( "%d", &selection );
    switch( selection ) 
    {
        case 1:
            printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
            printf("selected task for case 1 = %d\n", selectedTask);
            deleteNode( selectedTask );
        case 0:
            printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
            printNodes( 0 );
            printf("\n");
    }
}