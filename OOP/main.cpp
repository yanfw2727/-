#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
  char input[100],input2[100][3];
  long long  add=0,add1=0,total=0,tran[100],time=0,a=0;
      cout << "輸入:" << endl; 
      cin >> input;
  for(int i=0;i<100;i++){
        tran[i]=0;
    }
  for(int i=0;input[time]!='\0';i++){
        input2[i][0]=input[time];
        time++;
        input2[i][1]=input[time];
        time++;
        input2[i][2]='\0';
        }
  for(int i=0;i<50;i++){ //將中文轉成數字填入陣列 
    if(strncmp(input2[i],"負",2)==0)
        cout << "-" ;
    if(strncmp(input2[i],"零",2)==0)
        tran[i]=0;
    if(strncmp(input2[i],"壹",2)==0)
        tran[i]=1;
    if(strncmp(input2[i],"貳",2)==0)
        tran[i]=2;
    if(strncmp(input2[i],"參",2)==0)
        tran[i]=3;
    if(strncmp(input2[i],"肆",2)==0)
        tran[i]=4;
    if(strncmp(input2[i],"伍",2)==0)
        tran[i]=5;
    if(strncmp(input2[i],"陸",2)==0)
        tran[i]=6;
    if(strncmp(input2[i],"柒",2)==0)
        tran[i]=7;
    if(strncmp(input2[i],"捌",2)==0)   
        tran[i]=8;
    if(strncmp(input2[i],"玖",2)==0)
        tran[i]=9;
    if(strncmp(input2[i],"拾",2)==0)
        tran[i]=10;
    if(strncmp(input2[i],"佰",2)==0)
        tran[i]=100;
    if(strncmp(input2[i],"仟",2)==0)
        tran[i]=1000;
    if(strncmp(input2[i],"萬",2)==0)
        tran[i]=10000;
    if(strncmp(input2[i],"億",2)==0)
        tran[i]=100000000;
    if(input2[i]=='\0'){
        a=i; 
       break;
    }}
  for(int i=0;i<50;i++){
        if(tran[i-1]>=10&&(tran[i+1]==0||tran[i+1]>=10000)&&tran[i]<10){
            add=add+tran[i];
            }
        if(tran[i-1]==0&&(tran[i+1]==0||tran[i+1]>=10000)){
            add=add+tran[i];
            }
        if(tran[i]>=10&&tran[i]<9000){
            add=add+(tran[i-1]*tran[i]);
            }
        if(tran[i]>=10000&&tran[i]<90000000){
            total=total+(add*tran[i]);
            add=0;
        }
        if(tran[i]>=100000000){
            total=total+(add*tran[i]);
            add=0;
        }
}
  total=total+add;
  cout << total;
  cin.get();
  cin.get();
  return 0;
}
