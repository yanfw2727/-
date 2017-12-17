#include <stdio.h>
#include <math.h>
#include <stdlib.h>
static double X,Y;
float ox(double a,double b,double d, double x){
      if(a>0&&b>0){
       X=X+a;
       Y=Y+b;
       }
     if(x<0)
     return 0;
     d=d/2;
     ox(a+d,b+d,d,x-1);
     ox(a+d,b-d,d,x-1);
     ox(a-d,b+d,d,x-1);
     ox(a-d,b-d,d,x-1);
}
int main(){
    double a,b,d,x;
    printf("請輸入正方形中心點座標(a,b):"); 
    scanf("%lf %lf",&a,&b);
    printf("請輸入正方形每邊長度:");
    scanf("%lf",&d); 
    printf("請輸入重複次數x:");
    scanf("%lf",&x);
    ox(a,b,d,x);
    if(a>0&&b>0){
      X=X-a;
      Y=Y-b;
      }
    printf("X軸座標值總和為:%f\n",X);
    printf("Y軸座標值總和為:%f",Y);
    system("PAUSE");
    return 0;
}
