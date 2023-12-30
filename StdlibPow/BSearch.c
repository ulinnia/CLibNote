#include<stdio.h>
#include<stdlib.h>

#define COUNT 5

int Data[COUNT] = {99,54,86,31,1};

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int main(){
    qsort(Data, COUNT, sizeof(int), compare);
    int Input;
    scanf("%d", &Input);

    int *target = (int *)bsearch(&Input, Data, COUNT, sizeof(int), compare);
    if( target != NULL ){
        printf("Found item = %d\n", *target);
    }else{
        printf("Input couldn't be found in the array!!\n");
    }
    
    return 0;
}
/*
宣告一個隨機數陣列，裡面有五個元素
compare函數a-b是待會的qsort升序(小到大)排列，b-a則是降序
先將Data的元素做快速排序(升序排列)，
使用者輸入一個數，使用二元搜尋，尋找該陣列是否有相同的元素，
有則返回該值位址，否則回傳NULL
要執行bsearch的陣列，必須是已經排列好的!!!
*/