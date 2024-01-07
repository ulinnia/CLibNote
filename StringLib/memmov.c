#include <stdio.h>
#include <string.h>

int main () {
   char dest[] = "oldstring";           //定義兩個字串
   const char src[]  = "newstring";     //const不能修改

   printf("Before memmove dest = %s, src = %s\n", dest, src);//印出修改之前的兩個字串
   memmove(dest, src, 9);               //將src字串內容抓進dest字串
   printf("After memmove dest = %s, src = %s\n", dest, src); //印出修改後的兩個字串
                                        //dest字串內容會變成src的字串內容
   return(0);
}