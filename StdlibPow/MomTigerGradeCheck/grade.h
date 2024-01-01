#ifndef _GRADE_
#define _GRADE_

typedef struct data dat_t;
typedef struct Node nod_t;

typedef struct data{
    int Std_num;
    char name[10];
    double score;
} dat_t;


typedef struct Node{
    dat_t inf;
    nod_t *next;
} nod_t;

void Push(nod_t *headPtr);
void PrintList(nod_t *head, double limit);
void flushBuffer();
int Del(nod_t *head);

#endif