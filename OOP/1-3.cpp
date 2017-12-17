#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char t1[27],t2[27];
    int tt=0,i,j,ans,test=0,n=0,sum=0;
    FILE *data;
    data=fopen("t3.txt","r");
    fscanf(data,"%d",&tt);
    for(i=0;i<tt;i++){
      fscanf(data,"%s",t1);
      fscanf(data,"%s",t2);
      n=strlen(t1);
      for(j=0;j<n;j++){
        test=(int)t1[j]-(int)t2[j];
        if(test<0)
        test=test*-1;
        sum=sum+test;
        }
        printf("%d\n",sum);
        sum=0;
        }
        fclose(data);
        system("PAUSE");
        return 0;
        }
