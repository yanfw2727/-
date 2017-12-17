#include<iostream>
#include<iomanip>
using namespace std;
void memError()
{
	cout<<" memory aalocation error! ";
	return 0;
}
int main()
{
	int n,i,m=2,v;
	float **test;
	float A=0.0,B=0.0,C=0.0,D=0.0,a,b,G;
	cout<<" 幾組資料: ";
	cin>>n;
	test=new float*[2];
	if(!test)
		memError();
	for(i=0;i<n;i++)
		{
			test[i]=new float[n];
			if(!test[i])
			memError();	
		} 
	for(i=0;i<n;i++)
		{
			cout<<" 輸入mV: ";
			cin>>test[0][i];
			cout<<" 輸入度C: ";
			cin>>test[1][i];
			cout<<endl;	
		}
	for(i=0;i<n;i++)
		{
			A=A+test[0][i]*test[1][i];
		}
	for(i=0;i<n;i++)
		{
			B=B+test[0][i];
		}
	for(i=0;i<n;i++)
		{
			C=C+test[1][i];
		}
	for(i=0;i<n;i++)
		{
			D=D+test[0][i]*test[0][i];
		}
	a=(n*A-B*C)/(n*D-B*B);
	b=(C-a*B)/n;
	cout<<" The thermocouple equation : ";
	cout<<endl;
	cout<<" T = "<< a <<" *V+ "<< b ;
	cout<<" ***TEST*** ";
	cout<<" enter voltage (mV): ";
	cin>>v;
	G=a*v+b;
	cout<<" temperature (度c)= "<< G; 
	return 0;
}
