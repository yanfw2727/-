/*txt檔請按照key->text的順序來輸入 */ 

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
char matrix[5][5];
string text_use;

void get_Matrix(string key);
char get_Char(int a, int b);
bool get_Char_P(char l, int &a, int &b);
void get_Text(string t, bool e);
void run(int d);

int main()
{
	bool e;
	string  filei, fileo, key, cho, txt;
	cout << "請輸入要加(解)密的文字檔名稱(請加上.txt)";
	cin >> filei;
	cout << "請輸入要輸出的文字檔名稱(請加上.txt)"; 
	cin >> fileo;
	ifstream fin(filei.c_str());
	ofstream fout(fileo.c_str());
	
	cout << "請輸入要Encode(E)還是Decode(D)? " ;
	cin >>  cho;
	e = (cho[0] == 'e' || cho[0] == 'E');
	fin >> key;
	fin >> txt;
	
	get_Matrix(key);
	get_Text(txt, e);
	
	if(e) run(1);
	else run(-1);
	
	fout << "OUTPUT:\n=========" << endl;
	string::iterator si = text_use.begin(); int cnt = 0;
	while( si != text_use.end() )
	{
	    fout << *si; 
		si++; 
		fout << *si << " "; 
		si++;
	    if( ++cnt >= 26 ) fout << endl, cnt = 0;
	}
	fout << endl << endl;
	
	
	return 0;
	
}

void run(int dir)
{
	int a, b, c, d;
	string nt;
	for( string::const_iterator ti = text_use.begin(); ti != text_use.end(); ti++)
	{
		if(get_Char_P( *ti++, a, b))
			if(get_Char_P( *ti, c, d))
			{
				if( a == c) 
				{
					nt += get_Char( a, b + dir );
					nt += get_Char( c, d + dir );
				}
				else if (b == d)
				{
					nt += get_Char( a + dir, b );
					nt += get_Char( c + dir, d );
				}
				else
				{
					nt += get_Char( c, d );
					nt += get_Char( a, b );
				}
			} 
	}
	text_use = nt;
}

void get_Matrix(string key)
{
	string source = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	string use = "";
	for(string :: iterator si = key.begin(); si != key.end();si++)
	{
		*si = toupper( *si);
		if(*si < 65 || *si > 90) continue;
		if(use.find(*si) == -1) use += *si;
	}
	copy( use.begin(), use.end(), &matrix[0][0]);
}

char get_Char(int a, int b)
{
	return matrix[ (b + 5) % 5][ (a + 5) % 5];
}

bool get_Char_P(char l, int &a, int &b)
{
	for(int i = 0; i <5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(matrix[i][j] == l)
			{
				a = j; b = i; return true;
			}
		}
	}
	return false;
}

void get_Text(string text, bool e)
{
	for( string :: iterator si = text.begin(); si != text.end(); si++)
	{
		*si = toupper( *si );
		if( *si < 65 || *si > 90 ) continue;
		text_use += *si;
	}
	if (e) 
	{
		string nt = "";
		size_t len = text_use.length();
		for( size_t x = 0; x <len ; x += 2)
		{
			nt += text_use[x];
			if( x + 1 < len)
			{
				if( text_use[x] == text_use[x + 1]) nt += 'X';
				nt += text_use[x + 1];
			}
		}
		text_use = nt;
	}
	if( text_use.length() & 1) text_use = 'X';
}

 


