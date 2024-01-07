#include<assert.h>
#include "grade.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

/*
it's a recursion below. I want to arrange the stack data by high score to low score.
and if the score of Newnode is equal to the stack data,i want them arrange by low studentID to high studentID.
so it will compare the new node pointer and the current's(it isn't current because i give it the headPtr) next's score
*/

void findSpace(nod_t *current, nod_t *NewPtr){
    if(current->next != NULL && ((nod_t *)(current->next))->inf.score == NewPtr->inf.score && current->next->inf.Std_num < NewPtr->inf.Std_num){
        findSpace(current->next, NewPtr);           //check if the score equal and the NewPtr's studentID is bigger.
    }else if(current->next==NULL || ((nod_t *)(current->next))->inf.score <= NewPtr->inf.score){
        NewPtr->next = current->next;               //check if {NewPtr's score is equal or bigger} or the current->next is NULL(no data)
        current->next = NewPtr;                     //push NewPtr on the stack
    }else if (((nod_t *)(current->next))->inf.score > NewPtr->inf.score){
        findSpace(current->next, NewPtr);           //check if the NewPtr's score is lower
    } 
}

void Push(nod_t *headPtr){
    nod_t *NewPtr = (nod_t *)malloc(sizeof(nod_t));
    assert(NewPtr);                                 //give the NewPtr a memory
    dat_t element;                                  //declare a temp struct dat_t

    bool RInput = false;                            //bool to check if the studentID is repeated
    nod_t *current;                                 //it is wRongInput
    
    do{
        RInput = false;
        printf("Input StudentId<int>: ");
        scanf("%d", &element.Std_num);              //scanf a num for studentID
        current = headPtr->next;                    //the head for check loop (if the studentID has been used)

        while (current != NULL) {
            if (current->inf.Std_num == element.Std_num) {
                printf("This StudentID has been used!!!\n");
                RInput = true;                      //if wrongInput = true,this check repeat ID loop won't stop
                break;
            }
            current = current->next;                //check every Node
        } // check if the ID has been Used
    } while (RInput);

    printf("Input StudentName<string>: ");          //scanf the student name
    flushBuffer();                                  
    fgets(element.name, sizeof(element.name), stdin);//fgets will eat the '\n'
    size_t len = strlen(element.name);              //so check if it has '\n'
    if (len > 0 && element.name[len - 1] == '\n') {
        element.name[len - 1] = '\0';               //replace it by the sign of end'\0'
    }
    printf("Input StudentScore<double>: ");         //scanf score
    scanf("%lf", &element.score);
    flushBuffer();
    NewPtr->inf = element;                          //put element to the NewPtr->inf(dat_t data type)
    findSpace(headPtr, NewPtr);                     //put it into findspace function
    printf("\n");
}

void PrintList(nod_t *head, double limit){
    nod_t *current = head->next;                    //data start at head->next
    printf("\n%-10s %-10s %-10s\n", "StdID", "StdName", "StdScor");//print title
    while(current != NULL){
        if(current->inf.score <= limit){            //check if the node's score is under the limit
            printf("%-10d %-10s %-10.2f\n", current->inf.Std_num//print it
                                        , current->inf.name
                                        , current->inf.score);
        }
        current = current->next;                    //check every Node
    }
}

void flushBuffer(){
    while(getchar() != '\n')                        //eat '\n',rather than the 'scanf' eat it
        continue;
}

int Del(nod_t *head){
    printf("The StdID Which you want to Delete: ");
    int temp;
    scanf("%d", &temp);                             //get the studentID who you want to delete
    flushBuffer();
    nod_t *current = head;                          //set the current node = head
    while(current->next != NULL){                   //while current->next != NULL to skip the headPtr
        nod_t *target = current->next;              //the Ptr I want to compare is the current->next
        if(target->inf.Std_num==temp){              //if I get the ID who I want to delete
	    printf("==============================================\n");//printthe data
            printf("the student you Delete: %s\nID: %d\nScore: %lf\n",target->inf.name
                                                                   ,target->inf.Std_num
                                                                   ,target->inf.score);
	    printf("==============================================\n");
            current->next = current->next->next;    //change the current->next to the current->next->next
            free(target);                           //release the memory of current->next
            return 1;                               //return 1 present delete successfully
        }
        current = current->next;                    //or not found and get next
    }
    return 0;                                       //if I can't find the Data return 0 present it.
}