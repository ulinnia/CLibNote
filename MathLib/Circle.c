#include<stdio.h>
#include<math.h>

struct point{
    double x, y;
};

struct circle{
    struct point center;
    double r;
};

int main(){
    struct circle C1,C2;
    scanf("%lf %lf %lf %lf %lf %lf",&C1.center.x, &C1.center.y, &C1.r, &C2.center.x, &C2.center.y, &C2.r);
    double distance = sqrt(pow(C2.center.x-C1.center.x, 2)+ pow(C2.center.y-C1.center.y, 2));
    if(((distance+C2.r)<C1.r) || ((distance+C1.r)<C2.r)){
        printf("3\n");
    }else if (C1.center.x==C2.center.x && C1.center.y==C2.center.y && C1.r==C2.r){
        printf("2\n");
    }else if (distance<=C1.r+C2.r){
        printf("4\n");
    }else if (distance>C1.r+C2.r){
        printf("1\n");
    }
}
/*
依序輸入第一個圓的圓心x、y和半徑，
再輸入第二個圓的圓心x、y和半徑，
如果二個圓沒有重疊且無交點(兩圓心距離(distance)大於兩圓半徑相加),印出1,
如果二個圓剛好完全重疊(半徑和圓心位置皆相同),印出2,
如果一個圓剛好包住另一個圓且二者無交點(兩圓心距離(diatance)加上其中一個圓的半徑，會小於另一圓的半徑),印3,
如果二個圓有交點(兩圓心距離(distance)介在兩圓半徑和之內),印出4
用這個方法，從圓包圓無交點慢慢往外排(if)，否則有焦點的4的判斷，會吃掉在裡面無交點的3
*/