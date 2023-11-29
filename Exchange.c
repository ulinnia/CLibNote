#include<stdio.h>

void Exchange(){
    char a,b;
    scanf("%hhd%hhd",&a,&b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("After exchange.............\na = %hhd\nb = %hhd\n", a, b);
}

int main(){
    int a = 5428;
    a ^= 123;
    printf("%d\n",a);
    a ^= 123;
    printf("%d\n",a);
    return 0; 
}