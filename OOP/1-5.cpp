#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
using namespace std;

inline int gcd( int a, int b ) {
	if( a%b == 0 )
		return b;
	else
		return gcd(b,a%b );
    }
int main(){
    int in1,in2,in3,in4,in5,in6,a,b,c,d;
    char op;
    ifstream fin("T5.txt");
    while(fin>>in1){
        fin >> in2 >> in3 >> op >> in4 >> in5 >> in6;
        switch(op){
            case '+':a=in3*in6;
                     in2=in2+in1*in3;
                     in5=in5+in4*in6;
                     b=in2*in6+in3*in5;
                     c=b/a;
                     b=b%a;
                     d=gcd(b,a);
                     cout << c << " " << b/d  << " "<< a/d << endl;
                     break;
            case '-':a=in3*in6;
                     in2=in2+in1*in3;
                     in5=in5+in4*in6;
                     b=in2*in6-in3*in5;
                     c=b/a;
                     b=b%a;
                     d=gcd(b,a);
                     cout << c << " " << b/d  << " "<< a/d << endl;
                     break;
            case '*':a=in3*in6;
                     in2=in2+in1*in3;
                     in5=in5+in4*in6;
                     b=in2*in5;
                     c=b/a;
                     b=b%a;
                     d=gcd(b,a);
                     cout << c << " " << b/d  << " "<< a/d << endl;
                     break;
            case '/':in2=in2+in1*in3;
                     in5=in5+in4*in6;
                     a=in3*in5;
                     b=in2*in6;
                     c=b/a;
                     b=b%a;
                     d=gcd(b,a);
                     cout << c << " " << b/d  << " "<< a/d << endl;
                     break;
        }
                     
    }
    cin.get();
    cin.get();
    return 0;
}
