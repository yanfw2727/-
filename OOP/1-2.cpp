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
    printf("�п�J����Τ����I�y��(a,b):"); 
    scanf("%lf %lf",&a,&b);
    printf("�п�J����ΨC�����:");
    scanf("%lf",&d); 
    printf("�п�J���Ʀ���x:");
    scanf("%lf",&x);
    ox(a,b,d,x);
    if(a>0&&b>0){
      X=X-a;
      Y=Y-b;
      }
    printf("X�b�y�Э��`�M��:%f\n",X);
    printf("Y�b�y�Э��`�M��:%f",Y);
    system("PAUSE");
    return 0;
}
