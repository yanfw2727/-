#include <iostream>

using namespace std;

class Smart{
	public :
		int a;
		int b;
		int do_thing();
};
int Smart::do_thing(){
	return a+b;
}

int main() {
	Smart test;
	test.a = 10;
	test.b = 5;
	cout << test.do_thing();
	return 0;
}
