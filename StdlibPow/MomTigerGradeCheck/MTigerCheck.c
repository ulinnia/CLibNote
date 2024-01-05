#include<assert.h>
#include "grade.h"
#include <stdio.h>
#include<stdlib.h>

int main(){
    char choice;
    nod_t *head = (nod_t *)malloc(sizeof(nod_t));
    assert(head);
    head->next = NULL;
    double temp;
    int DelSucc;

    do {
        printf("1 => Add A Data\n");
        printf("2 => Give Me The Lower Limit.I Will Give You Those Who's Grade Is Under The Limit(Include The Limit)\n");
        printf("3 => Give Me The StdID To Delete The Data\n");
        printf("4 => End The Program\n");
        printf("Give Me The Number About What You Want To Do: ");
        choice = getchar();
        flushBuffer();
        switch (choice){
            case '1':
                Push(head);
                break;            
            case '2':
                printf("\nPlease Input The Limit: ");
                scanf("%lf", &temp);
                flushBuffer();
                if(temp<60){
                    printf("\nLet's Check!!Who Will Get Into The Big Trouble!!!\n");
                }
                printf("===================================================");
                PrintList(head, temp);
                printf("===================================================\n");
                break;
            case '3':
                int DelSucc = Del(head);
                (DelSucc==1)? printf("Delete Success!\n\n\n"):printf("Get The Wrong StdID!!\n");
                break;
            case '4':
                printf("Bye Bye!!!Momtiger ^_^\n");
                break;
            default:
                printf("Input Error!!!!\n");
        }
    }while(choice != '4');
    return 0;
}
