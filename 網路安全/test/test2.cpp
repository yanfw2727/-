#include <iostream>
using namespace std;


void AscToBit(const char *in)
{
	int m[8][4];
	char test[8];
	for(int i = 0; i < 8; i++){
		test[i] = in[i];
	}
	for(int j = 0; j < 8; j++)
	{
		 if(test[j] == 'a')
		 	test[j] = 10;
		 if(test[j] == 'b')
		 	test[j] = 11;
		 if(test[j] == 'c')
		 	test[j] = 12;
		 if(test[j] == 'd')
		 	test[j] = 13;
		 if(test[j] == 'e')
		 	test[j] = 14;
		 if(test[j] == 'f')
		 	test[j] = 15;
		for(int i = 0; i < 4; i++)
		{
			m[j][i] = test[j] %2;
			test[j] = test[j] / 2;
		}
	}
	for(int j = 0; j < 8; j++){
		for(int bottom=0,top =3; bottom<4; bottom++,top--)
		{
			cout << m[j][top];
		}
	cout << " ";
	}
}
int main(){
	
	char a[8];
	string t;
	cout << "test:" << endl;
	cin >> a;
	AscToBit(a);
}
