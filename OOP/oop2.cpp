#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class String {
    
private:
    int n ;
    char *input;
public:
    String(){
        n = 1000;
        input = new char[ n*10 ];
    }
    ~String(){
        delete []input;
    }
    void GetChar() {
        cin >> input;
        n = strlen( input );
    }
    void Change () {
    int a ;
        for(int i = 0 ;i < n ;i++ ) {
            a = static_cast < int > ( input [ i ] );
            if ( a >= 97&& a <= 122)
                a = a - 32 ;
            input [ i ] = static_cast < char > ( a );
        }}
    void PrintOut () {
        cout << input;
    }
};
  int  main( ) {
    String str;
    str.GetChar();
    str.Change();
    str.PrintOut();
    cin.get();
    return 0; 
}   
