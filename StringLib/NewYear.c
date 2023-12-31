#ifdef __linux__
    #define OS_NAME "Linux"
#elif _WIN32
    #define OS_NAME "Windows"
#else
    #error "Unsupported operating system"
#endif

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    FILE *file = fopen("test.txt", "w");
    if(file == NULL){
        fprintf(stderr, "can't open the textFile!!!\n");
        return 1;
    }
    
    fseek(file, 0, SEEK_SET);
    char FuMatrix[] = {
        ' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ','\n',
        ' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','\n',
        ' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ','\n',
        '*','*','*','*','*',' ','*',' ',' ',' ','*',' ','\n',
        ' ',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','\n',
        ' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','\n',
        ' ','*','*','*',' ',' ',' ','*','*','*',' ',' ','\n',
        ' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','\n',
        '*','*','*','*','*',' ',' ','*','*','*',' ',' ','\n',
        '*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','\n',
        '*',' ','*',' ','*','*','*',' ','*',' ','*','*','\n',
        ' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','\n',
        ' ',' ','*',' ',' ','*','*','*','*','*','*','*','\n',
        ' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','\n',
        ' ',' ','*',' ',' ','*','*',' ','*',' ','*','*','\n',
        ' ',' ','*',' ',' ',' ','*',' ','*',' ','*',' ','\n',
        ' ',' ','*',' ',' ',' ',' ','*','*','*',' ',' ','\n'
    };

    size_t count = sizeof(FuMatrix)/sizeof(FuMatrix[0]);

    if(fwrite(FuMatrix, sizeof(char), count, file) != count){
        fprintf(stderr, "Writting got wrong!!!\n");
        fclose(file);
    }

    fclose(file);
    
    char command[50];
    (OS_NAME=="Linux")? strcpy(command, "cat test.txt"):strcpy(command, "type test.txt");
    system(command);
    return 0;
}
/*
打開test.txt文件(假如沒有就在該目錄下新建一個)以w模式
判斷假如沒開成功印出無法打開檔案在stderr
將文件檔輸入開始處定到文件的開頭(fseek)
輸入一個一維陣列，計算陣列裡面總共有幾個元素(fwrite會用到)，
輸入陣列元素到該文件內，假如輸入的元素量不等於該陣列元素量，印出警告
關閉檔案
新增一個陣列儲存命令(system(指標))，這個陣列是為了符合該變數型態
複製要下到shell的命令，到該陣列，
用system(command)函數執行他
該命令(cat)是印出剛剛文件裡的所有元素
*/