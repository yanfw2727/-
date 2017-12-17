#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
  char input[100],input2[100][3],output[30];
  long long  add=0,add1=0,total=0,tran[100],time=0,a=0,b=0;
  double c=0;
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
       break;
    }}
  for(int i=0;i<50;i++){
        if((tran[i+1]==0||tran[i+1]>=10000)&&tran[i]<10){
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
  sprintf(output,"%lld",total);
  for(int i=0;i<50;i++){
    if(output[i]=='\0'){
    a=i;
    break;
}}
if(a==1)
cout << output[0];
if(a==2)
cout << output[0]<< output[1];
if(a==3)
cout << output[0]<< output[1]<< output[2];
if(a==4)
cout << output[0]<<   ","   << output[1]<< output[2]<< output[3];
if(a==5)
cout << output[0]<< output[1]<<   ","   << output[2]<< output[3]<< output[4];
if(a==6)
cout << output[0]<< output[1]<< output[2]<<   ","   << output[3]<< output[4]<< output[5];
if(a==7)
cout << output[0]<<   ","   << output[1]<< output[2]<< output[3]<<   ","   << output[4]<< output[5]<< output[6];
if(a==8)
cout << output[0]<< output[1]<<   ","   << output[2]<< output[3]<< output[4]<<   ","   << output[5]<< output[6]<< output[7];
if(a==9)
cout << output[0]<< output[1]<< output[2]<<   ","   << output[3]<< output[4]<< output[5]<<   ","   << output[6]<< output[7]<< output[8];
if(a==10)
cout << output[0]<<   ","   << output[1]<< output[2]<< output[3]<<   ","   << output[4]<< output[5]<< output[6]<<   ","   << output[7]<< output[8]<< output[9];
if(a==11)
cout << output[0]<< output[1]<<   ","   << output[2]<< output[3]<< output[4]<<   ","   << output[5]<< output[6]<< output[7]<<   ","   << output[8]<< output[9]<< output[10];
if(a==12)
cout << output[0]<< output[1]<< output[2]<<   ","   << output[3]<< output[4]<< output[5]<<   ","   << output[6]<< output[7]<< output[8]<<   ","   << output[9]<< output[10]<< output[11];
  
  cin.get();
  cin.get();
  return 0;
}
