#include<assert.h>
#include "grade.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

void findSpace(nod_t *current, nod_t *NewPtr){
    if(current->next != NULL && ((nod_t *)(current->next))->inf.score == NewPtr->inf.score && current->next->inf.Std_num < NewPtr->inf.Std_num){
        findSpace(current->next, NewPtr);
    }else if(current->next==NULL || ((nod_t *)(current->next))->inf.score <= NewPtr->inf.score){
        NewPtr->next = current->next;
        current->next = NewPtr;
    }else if (((nod_t *)(current->next))->inf.score > NewPtr->inf.score){
        findSpace(current->next, NewPtr);
    } 
}

void Push(nod_t *headPtr){
    nod_t *NewPtr = (nod_t *)malloc(sizeof(nod_t));
    assert(NewPtr);
    dat_t element;

    bool RInput = false;
    nod_t *current;
    
    do{
        RInput = false;
        printf("Input StudentId<int>: ");
        scanf("%d", &element.Std_num);
        current = headPtr->next;

        while (current != NULL) {
            if (current->inf.Std_num == element.Std_num) {
                printf("This StudentID has been used!!!\n");
                RInput = true; 
                break;
            }
            current = current->next;
        } // check if the ID has been Used
    } while (RInput);

    printf("Input StudentName<string>: ");
    flushBuffer();
    fgets(element.name, sizeof(element.name), stdin);
    size_t len = strlen(element.name);
    if (len > 0 && element.name[len - 1] == '\n') {
        element.name[len - 1] = '\0'; 
    }
    printf("Input StudentScore<double>: ");
    scanf("%lf", &element.score);
    flushBuffer();
    NewPtr->inf = element;
    findSpace(headPtr, NewPtr);
    printf("\n");
}

void PrintList(nod_t *head, double limit){
    nod_t *current = head->next;
    printf("\n%-10s %-10s %-10s\n", "StdID", "StdName", "StdScor");
    while(current != NULL){
        if(current->inf.score <= limit){
            printf("%-10d %-10s %-10.2f\n", current->inf.Std_num
                                        , current->inf.name
                                        , current->inf.score);
        }
        current = current->next;
    }
}

void flushBuffer(){
    while(getchar() != '\n')
        continue;
}

int Del(nod_t *head){
    printf("The StdID Which you want to Delete: ");
    int temp;
    scanf("%d", &temp);
    flushBuffer();
    nod_t *current = head;
    while(current->next != NULL){
        nod_t *target = current->next;
        if(target->inf.Std_num==temp){
	    printf("==============================================\n");
            printf("the student you Delete: %s\nID: %d\nScore: %lf\n",target->inf.name
                                                                   ,target->inf.Std_num
                                                                   ,target->inf.score);
	    printf("==============================================\n");
            current->next = current->next->next;
            free(target);
            return 1;
        }
        current = current->next;
    }
    return 0;
}
