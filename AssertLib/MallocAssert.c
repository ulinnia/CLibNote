#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    int *a = (int *)malloc(sizeof(int));
    assert(a);
    *a = 8;
    printf("%d\n",*a);
    free(a);
}
/*
借一塊int(4bytes)大小的記憶體，假如沒借到就警告，並跳出
有就存入8，並印出來，然後釋放該記憶體
*/