#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MyArray{
    private :
            int *data;
            int max_size,use_size;
    public  :// constructures and destructure
        MyArray(){
            data = NULL;
            max_size = 0;
            use_size = 0;
        }
        MyArray(const MyArray &m){
            data = NULL;
            use_size = m.use_size;
            max_size = m.use_size;
            if( max_size <= 0 )
			return;
		    data = new int [max_size];
		for( int i = 0; i < use_size; ++i )
			data[i] = m.data[i];
        }
        MyArray( int size, int init = 0 ) {
            data = NULL;
            use_size = size;
            max_size = size;
	        if( size <= 0 )
			     return;
		    data = new int [max_size];
		    for( int i = 0; i < use_size; ++i )
			data[i] = init;
        }
        virtual ~MyArray() {
		    if( data != NULL )
		       	delete [] data;
	    }
	public  : // public methods
	    MyArray& operator = ( const MyArray &m ) {
		    if( max_size < m.use_size ) {
			if( data != NULL )
				delete [] data;
			max_size = m.use_size;
			data = new int [ max_size ];
		}
		    use_size = m.use_size;
		    for( int i = 0; i < use_size; ++i )
			data[i] = m.data[i];
	       	return *this;
	    }
	
	    int& operator [] ( const int index ) {
		    return data[index];
       	}
       	void sortInc( const MyArray &m) {
            int tmp; 
            for (int i = 0; i < m.use_size - 1; i++){
                for (int j = 0; j < m.use_size - i - 1 ; j++){
                    if( m.data[j] > m.data[j+1] ){
                        tmp = m.data[j];
                        m.data[j] = m.data[j+1];
                        m.data[j+1] = tmp;
                }
            }
        }}
        void sortDec( const MyArray &m) {
            int tmp;
            for (int i = 0; i < m.use_size - 1; i++){
                for (int j = 0; j < m.use_size - i - 1 ; j++){
                    if( m.data[j] < m.data[j+1] ){
                        tmp = m.data[j];
                        m.data[j] = m.data[j+1];
                        m.data[j+1] = tmp;
                }
            }
        }}
	
	inline int size() const { return use_size; }
	
	inline int served() const { return max_size; }
};
int main() {
    srand( time(NULL) );
    int n;
    cout << "Input how many numbers :" << endl;
    cin >> n;
	MyArray a( n );
	for( int i = 0; i < a.size(); ++i )
		a[i] = rand();
	MyArray b(a);
	MyArray c = a;
	b.sortInc(b);
	c.sortDec(c);
	cout << "A: ";
	for( int i = 0; i < a.size(); ++i )
		cout << a[i] << " ";
	cout << endl << "Ascend: ";
	for( int i = 0; i < b.size(); ++i )
		cout << b[i] << " ";
	cout << endl << "Descend: ";
	for( int i = 0; i < c.size(); ++i )
		cout << c[i] << " ";
	cout << endl;
	cin.get();
    cin.get();
	return 0;
}
