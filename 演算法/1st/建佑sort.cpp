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
	
    array= new double[n];//�ʺA�ŧi�}�C 
	int x;
	int i;
	for(int k=0;k<n;k++)  //��P 
	{
array[k]=k+1;
	}
	
	 for(int ii=0;ii<=n;ii++){ //�~�P 
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
countcompare++;//�p�⦳�S���e���Ʀr 
}
array[i]=x;	


}

finish = clock();
cout<<"-------�ڬO���νu-----" << endl;
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
