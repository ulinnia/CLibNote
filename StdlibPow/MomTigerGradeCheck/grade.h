#ifndef _GRADE_         //if no define _GRADE_ do the define below
#define _GRADE_         //define this .h file as _GRADE_

typedef struct data dat_t;      //declare a data type as dat_t
typedef struct Node nod_t;      //declare a data type(include next node pointer) as nod_t

typedef struct data{
    int Std_num;                //define the dat_t include studentID
    char name[10];              //student name
    double score;               //student's score
} dat_t;


typedef struct Node{
    dat_t inf;                  //define the nod_t include a dat_t struct
    nod_t *next;                //and a nod_t pointer to the next Node
} nod_t;

void Push(nod_t *headPtr);      //declare the Push for main function to use to push a new Node to the chain
void PrintList(nod_t *head, double limit);      //the PrintList to print the score under the limit(the student's data)
void flushBuffer();             //to prevent the scanf() eat the '\n' 
int Del(nod_t *head);           //help user to delete a student ID (everyData about the student)

#endif                          //define _GRADE_ end