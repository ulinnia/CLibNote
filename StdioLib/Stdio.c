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
/*
定一個FILE指標pf，指向a.txt以a+的模式
從裡面抓東西，假如沒抓到任何東西，印出沒抓到
在該文件檔末加一行字xxxxxxxx
關閉檔案fclose(FILE指標)
*/