#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char a[200];
    scanf("%s", a);

    while (strcmp(a,"END")!=0){
        for(int i=0; i<strlen(a); i++){
            if(isalpha(a[i])){
                if(isupper(a[i])){
                    a[i] = tolower(a[i]);
                }else{
                    a[i] = toupper(a[i]);
                }
            }
        }
        if (getchar()!=' '){
            printf("%s\n",a);
        }else{
            printf("%s ",a);
        }
        scanf("%s", a);
    }
    return 0;
}

/*
持續接受輸入字串，並儲存在陣列a(每次loop(scanf)截到空格或換行)，
假如輸入等於"END"結束迴圈【否則確認每個字元是否為英文，
是則確認是否為大寫，是則轉換成小寫，否則轉換成大寫，
假如不是空格就是換行，判斷不是空格，輸出多一個換行，否則多一個空格
】括號內為迴圈
*/