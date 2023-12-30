#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char command[50];

    strcpy(command, "ls -la");
    system(command);
    return 0;
}