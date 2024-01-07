#include<assert.h>
#include "grade.h"
#include <stdio.h>
#include<stdlib.h>

int main(){
    char choice;
    nod_t *head = (nod_t *)malloc(sizeof(nod_t));       //create the stack head
    assert(head);
    head->next = NULL;                                  //set the NULL to the head->next
    double temp;                                        //declare the limit is double
    int DelSucc;                                        //declare the return value about the data delete

    do {
        printf("1 => Add A Data\n");
        printf("2 => Give Me The Lower Limit.I Will Give You Those Who's Grade Is Under The Limit(Include The Limit)\n");
        printf("3 => Give Me The StdID To Delete The Data\n");
        printf("4 => End The Program\n");
        printf("Give Me The Number About What You Want To Do: ");
        choice = getchar();                             //get what to do
        flushBuffer();
        switch (choice){
            case '1':
                Push(head);                             //1=>push function
                break;            
            case '2':
                printf("\nPlease Input The Limit: ");
                scanf("%lf", &temp);                    //2=>delete func
                flushBuffer();
                if(temp<60){                            //if limit<60 someone fail
                    printf("\nLet's Check!!Who Will Get Into The Big Trouble!!!\n");
                }
                printf("===================================================");
                PrintList(head, temp);                  //printlist func
                printf("===================================================\n");
                break;
            case '3':
                int DelSucc = Del(head);                //delete func,if delete fail print(warn)
                (DelSucc==1)? printf("Delete Success!\n\n\n"):printf("Get The Wrong StdID!!\n");
                break;
            case '4':
                printf("Bye Bye!!!Momtiger ^_^\n");     //user want to leave
                break;
            default:
                printf("Input Error!!!!\n");            //default
        }
    }while(choice != '4');                              //check if it isn't leave signal
    return 0;
}
