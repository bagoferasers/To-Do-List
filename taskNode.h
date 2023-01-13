#ifndef _taskNode_h
#define _taskNode_h

struct taskNode
{
    int priority;
    int timeInMinutes;
    int timeInHours;
    char* name;
    char* description;
    char* dateDue;
} taskNode;

void insertNode( struct taskNode** s, struct taskNode* t );

struct taskNode buildNode( int p, int tM, int tH, char* n, char* d, char* dD );

void printNodes( struct taskNode** s );

void freeNodes( struct taskNode** s );

#endif