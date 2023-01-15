#ifndef _taskNode_h
#define _taskNode_h

extern int count;
extern struct taskNode* tasks;

struct taskNode
{
    int priority;
    int timeInMinutes;
    int timeInHours;
    char* name;
    char* description;
    char* dateDue;
} taskNode;

void insertNode( struct taskNode t );

struct taskNode buildNode( int p, int tM, int tH, char* n, char* d, char* dD );

void printNodes( int j );

void swap( struct taskNode* a, struct taskNode* b );

//void deleteNode( struct taskNode s[ ], struct taskNode t );

//void updateNode( struct taskNode s[ ], struct taskNode t );

#endif