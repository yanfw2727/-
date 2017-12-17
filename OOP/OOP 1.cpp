#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
int strToFloatArray(const char *str,float *&des){
	int n=0;
	for(int i=0;str[i]!='\0';++i){
		if(isdigit(str[i])){
			++n;
			do{
                ++i;
            }while(isdigit(str[i]));
			if(str[i]=='.')
				do{
                    ++i
                ;}while(isdigit(str[i]));
		}
	}
	des=new float[n];
	for(int i=0,idx=0;idx<n;++i){
		bool negative=bool(str[i]=='-');
		if(negative)
			++i;
		if(isdigit(str[i])){
			float num = 0.0, bas = 0.1;
			do{
                num=num*10+static_cast<float>(str[i++]-'0');
             }while(isdigit(str[i]));
			if( str[i] == '.' ) {
				++i;
				while(isdigit(str[i])){
					num+=bas*static_cast<float>( str[i++] - '0' );
					bas*=0.1;
				}
			}
			if(negative)
            num=-num;
            else 
            num;
			des[idx++]=num;
		}
	}
	return n;
}
using namespace std;

int main(){
    fstream file;
    float **ptr,*buf1,*buf2;
    int n,test;
    float suma=0,sumv2=0,sumv=0,sumt=0,a=0,b=0;
    string buff1, buff2;
    
    ifstream fin("132.txt");
    getline( fin, buff1 );
    getline( fin, buff2 );
    
    n=strToFloatArray( buff1.c_str(),buf1 );
    strToFloatArray( buff2.c_str(),buf2 );
    for(int i=0;i<n;++i)
        suma=suma+(buf1[i]*buf2[i]);
    for(int i=0;i<n;++i)
        sumv=sumv+buf1[i]; 
    for(int i=0;i<n;++i)
        sumt=sumt+buf2[i]; 
    for(int i=0;i<n;++i)
        sumv2=sumv2+(buf1[i]*buf1[i]);
    a=(static_cast<float>(n)*suma-sumv*sumt)/(static_cast<float>(n)*sumv2-sumv*sumv);
    b=(sumt-a*sumv)/static_cast<float>(n);
    cout << "The thermocouple equation:"<<endl << endl;
    cout << "   T=" << a << "*V+"<< b <<endl << endl;
    cout << "          ***TEST***" <<endl << endl;
    cout << "   Enter voltage (mv):";
    cin >> test;
    cout << endl << "   Temperture (oC) = " << a*test+b; 
    fin.close();
    cin.get();
    cin.get();
    return 0;
}
    
