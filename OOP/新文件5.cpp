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

int main() {
	int n;
	float *v, *t;
	std::string input;
	std::getline( std::cin, input );
	 strToFloatArray( input.c_str(), v );
	std::getline( std::cin, input );
	n= strToFloatArray( input.c_str(), t );
	float vSum = 0.0, tSum = 0.0, vvSum = 0.0, vtSum = 0.0;
	for( int i = 0; i < n; ++i ) {
		vSum += v[i];
		tSum += t[i];
		vvSum += v[i] * v[i];
		vtSum += v[i] * t[i];
	}
	float a = ( static_cast<float>(n)*vtSum - vSum*tSum ) / ( static_cast<float>(n)*vvSum - vSum*vSum );
	float b = ( tSum - a*vSum ) / static_cast<float>(n);
	std::cout << "T = " << a << "*V + " << b << std::endl;
	cin.get();
	return 0;
}

    
