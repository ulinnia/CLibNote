#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define COUNT 12

int Data[COUNT] = {99,54,86,31,1,87,12,54,87,32,54,532};

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int main(){
    time_t start_t, end_t, curtime;
    double diff_t;

    start_t = clock();      //儲存程式起始時間
    qsort(Data, COUNT, sizeof(int), compare);//排序
    end_t = clock();        //儲存排序完成時間

    diff_t = (double)(end_t - start_t) ;//計算中間經過幾個clock
    for (int i=0; i<12; i++){
        printf("%d ", Data[i]);         //印出來確保有正確排序
    }
    printf("\n");
    printf("Execution clocks = %f (clocks)\n", diff_t);//印出經歷過幾個clock
    printf("it takes %f seconds.\n", diff_t/ CLOCKS_PER_SEC);//印出經過秒數(clock/clock per second)

    time(&curtime);//傳回自紀元（00:00:00 UTC，1970 年 1 月 1 日）以來的時間，以"秒"為單位。
    char *timeString = ctime(&curtime);// 使用 ctime 將時間轉換成人看得字符串(年、月、日、日期)
    printf("Current time: %s\n", timeString);// 印结果

    struct tm *localTime = localtime(&curtime);//localTime指向一個結構tm的資料，裡面定義了以下
//     struct tm {
//    int tm_sec;         /* seconds,  range 0 to 59          */
//    int tm_min;         /* minutes, range 0 to 59           */
//    int tm_hour;        /* hours, range 0 to 23             */
//    int tm_mday;        /* day of the month, range 1 to 31  */
//    int tm_mon;         /* month, range 0 to 11             */
//    int tm_year;        /* The number of years since 1900   */
//    int tm_wday;        /* day of the week, range 0 to 6    */
//    int tm_yday;        /* day in the year, range 0 to 365  */
//    int tm_isdst;       /* daylight saving time             */
// };
            //以上都能從指標提取ex:提取秒=>localTime->tm_sec
    printf("Current local time: %s", asctime(localTime));
        //asctime回傳一個指向代表tm結構的字串(pointer)
        //印出該字串
    return 0;
}