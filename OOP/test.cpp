#include <cstdio>  
#include <cstring>  
using namespace std;  
  
int N;  
void farey (int a,int b,int c,int d)  
{  
    if (b+d > N) return ;  
    if (b+d == N)  
    {  
        printf("%d/%d",a+c,b+d);  
        if(a+c != N-1) printf(",");  
        return ;  
    }  
    farey(a,b,a+c,b+d);  
    printf("%d/%d,",a+c,b+d);  
    farey(a+c,b+d,c,d);  
}  
  
int main ()  
{  
    int T;  
    while (T--)  
    {  
        scanf("%d",&N);
		printf("%d,",0);  
        farey(0,1,1,1);  
        printf(",%d",1);
        printf("\n");  
    }  
    
}
