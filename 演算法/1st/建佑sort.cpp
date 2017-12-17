#include<iostream>
#include<cstdlib> 
#include <time.h>
using namespace std;

int main(void)
{
		
	srand(time(NULL));
	clock_t start, finish;
	   
	double *array;
    int n;
    double   duration;   
    
	double countcompare=0,countchange=0;
    cin>>n;
	
    array= new double[n];//動態宣告陣列 
	int x;
	int i;
	for(int k=0;k<n;k++)  //制牌 
	{
array[k]=k+1;
	}
	
	 for(int ii=0;ii<=n;ii++){ //洗牌 
        int n1=(rand()*rand()+rand())%n;		
        int n2=(rand()*rand()+rand())%n;
        
        int temp=array[n1];
        array[n1]=array[n2];
        array[n2]=temp;
 
    }
    
  /*  
	
	for(int k=0;k<n;k++)
	{
	cout<<array[k]<<endl;
	}
*/ 
start = clock();


	for(int j=2;j<=n;j++)
	{
	 
		i=j-1;
		x=array[j-1];
		
		while(x<array[i-1]&&i>0)
{
countcompare++;
array[i]=array[i-1];
i=i-1;
countchange++;
}
if(i!=0)
{
countcompare++;//計算有沒有前面數字 
}
array[i]=x;	


}

finish = clock();
cout<<"-------我是分割線-----" << endl;
/*	for(int k=0;k<n;k++)
	{
	cout<<array[k]<<endl;
	}/*/ 
	duration = (double)(finish - start);
	cout<<"time="<<duration<<endl;
	cout<<"change="<<countchange<<endl;
	cout<<"compare="<<countcompare<<endl;
	

		delete [] array;
	return 0;
}
