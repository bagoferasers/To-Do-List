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

#endif