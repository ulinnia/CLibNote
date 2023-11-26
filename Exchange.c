#include<stdio.h>

int main(){
    char a,b;
    scanf("%hhd%hhd",&a,&b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("After exchange.............\na = %hhd\nb = %hhd\n", a, b);
    return 0;
}