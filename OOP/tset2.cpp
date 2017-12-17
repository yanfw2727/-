#include <string>
#include <iostream> 

// data array assign to des, and function return the size of array
int strToIntArray( const char *str, int * &des ) {
    // count number of integers contained in str
    int n = 0;
    for( int i = 0; str[i] != '\0'; ++i ) {
        if( isdigit( str[i] ) ) {
            ++n;
            do { ++i; } while( isdigit( str[i] ) );
        }
    }
    // assign data to array 
    des = new int[n];
    for( int i = 0, idx = 0; idx < n; ++i ) {
        bool negative = bool(str[i] == '-');
        if( negative )
            ++i;
        if( isdigit( str[i] ) ) {
            int num = 0;
            do { num = num * 10 + static_cast<int>( str[i++] - '0' ); } while( isdigit( str[i] ) );
            num = (negative)?-num:num;
            des[idx++] = num;
        }
    }
    return n;
}
int main() {
    int n, *arr;
    std::string input;
    std::getline( std::cin, input );
    n = strToIntArray( input.c_str(), arr );
    for( int i = 0; i < n; ++i )
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
