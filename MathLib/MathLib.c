#include <stdio.h>
#include<math.h>

#define PI 3.14159265
#define RADIAN (PI/180.0)           //set degree turn to radian parameter

void Arcsin(){
    double degree;                   //declare double type variable ret
    double sin = 1.0/2.0;           //sin value
    degree = asin(sin)*(1/RADIAN); //get the arcsin(sin value)output is radian.So multiply (180.0/PI)to get the degree
    printf("sin = 1/2 ;from Arcsin get the degree = %lf\n",degree);
}                                   //don't forget the float (4.0)like this.Otherwise,only get the integer operation
                                    //print long float type

void NaturalLog(){
    double x;
    x = 2.7;                        //get the natural log of 2.7
    printf("log(%lf) = %lf\n", x, log(x));
}

void SinFunction(){
    double x = 30.0;                //set degree
    double ret = x*RADIAN;          //sin need radian,so degree multiply the parameter
    printf("sin 30 degree is equal to: %lf\n",sin(ret));
}

void PowerFunction(){
    printf("Value 8.0 ^ 3 = %lf\n", pow(8.0, 3));   //print 8.0 raised to the power of 3

    printf("Value 2.0 ^ 10 = %lf\n", pow(2.0, 10)); //print 2.0 raised to the power of 10
}

int main(){
    printf("Square root of %lf is %lf\n", 2.0, sqrt(2));    //get the square root of 2.0
    Arcsin();
    NaturalLog();
    SinFunction();
    PowerFunction();
    return 0;
}
/*
印出math函數產生的各種輸出
*/