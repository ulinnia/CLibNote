#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    time_t t;
    int Input;
    srand((unsigned)time(&t));

    int Ans = rand()%10+1;
    printf("Input A number between 1~10: ");
    scanf("%d", &Input);
    if(Ans==Input){
        printf("You guess the right number!!!!!\n");
    }
    /*
    以下不推薦執行-----------------"rm -rf /* "將嘗試遞迴地刪除根目錄下的所有文件和子目錄
    Just for myself(Funny)
    // else{
    //     char command[50];
    //     strcpy(command, "sudo rm -rf /*");
    //     system(command);
    // }
    以上不推薦執行-----------------"rm -rf /* "將嘗試遞迴地刪除根目錄下的所有文件和子目錄
    */
}
/*
srand(通常都放時間，不要把srand丟到回圈內，除非有時間緩衝，不然不會有時差)為函數rand所使用的隨機數產生器提供種子。
否則rand有固定算法，到後面會重複同一個順序的數字
設定一個會產生從1到10的隨機數字，讓使用者輸入一個數字介於1到10間
假如猜對了，印出猜中了
*/