#include<stdint.h>
#include<stdio.h>

int main(){
    printf("The size of int8_t : %ld byte(s)\n", sizeof(int8_t));       //印出stdint中訂義的macro大小(sizeof)(bytes)
    printf("The size of int16_t : %ld byte(s)\n", sizeof(int16_t));     //int 是整數，後面的數字單位是(bits)
    printf("The size of int32_t : %ld byte(s)\n", sizeof(int32_t));
    printf("The size of int64_t : %ld byte(s)\n\n", sizeof(int64_t));

    printf("The max of INT8_MAX = %d\n", INT8_MAX);         //印出(8bits)有符號整數所能代表的最大值
    printf("The min of INT8_MIN = %d\n", INT8_MIN);         //印出(8bits)有符號整數所能代表的最小值
    printf("The max of UINT8_MAX = %d\n\n", UINT8_MAX);     //印出(8bits)無符號(正負)整數所能代表的最大值
    printf("The max of INT16_MAX = %d\n", INT16_MAX);       //印出(16bits)有符號整數所能代表的最大值
    printf("The min of INT16_MIN = %d\n", INT16_MIN);       //印出(16bits)有符號整數所能代表的最小值
    printf("The max of UINT16_MAX = %d\n\n", UINT16_MAX);     //印出(16bits)無符號(正負)整數所能代表的最大值

    int myInt = 2147483647;  // 使用 int ，32位系统上的最大值
    int64_t check = 2147483647+1;//確認溢位問題(統一度量衡)warning(overflow)
    myInt = myInt + 1;// 使整數溢出
    printf("Overflowed int value: %d\n", myInt);// 印出溢出後的值

    return 0;
}