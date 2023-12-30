#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE * pf = fopen("a.txt","a+");

    if (fgetc(pf)==EOF){
        printf("didn't get any words!!!\n");
    }
    fprintf(pf,"%s","xxxxxxxx");

    fclose(pf);
    return(0);
}