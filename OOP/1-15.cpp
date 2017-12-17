#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

typedef std::string String;

int record[20][10];
int match[20];

static const int MAX=9999;

void ReadData( const String &fileName ) {
	std::ifstream fin( fileName.c_str() );
	String line;
	for( int i = 0; i < 20; ++i ) {
		std::getline( fin, line );
		int idx = static_cast<int>(line[0] - 'A') * 10;
		idx += atoi( line.substr(1, 2).c_str() ) - 1;
		int t = 1, offset;
		for( int j = 0; j < 10; ++j ) {
			offset = line.find_first_of( ",", t ) + 1;
			record[idx][j] = atoi( line.substr( offset ).c_str() );
			t = offset + 1;
		}
	}
}

void init() {
	ReadData("T15.txt");
	for( int i = 0; i < 20; ++i )
		match[i] = 0;
}

int find( int arr[], int n ) {
	for( int i = 0; i < 10; ++i ) {
		if( arr[i] == n )
			return i;
	}
	return MAX;
}

void compute() {
	for( int i = 0; i < 10; ++i ) {
		for( int n = 1; n <= 10; ++n ) {
			if( match[9+n] > 0 )
				continue;
			int min_s = MAX, min_r = MAX;
			for( int s = 0; s < 10; ++s ) {
				if( match[s] > 0 || record[s][i] != n )
					continue;
				int tmp_r = find( record[9+n], s+1 );
				if( min_r > tmp_r ) {
					min_r = tmp_r;
					min_s = s;
				}
			}
			if( min_s != MAX ) {
				match[min_s] = n;
				match[9+n] = min_s + 1;
			}
		}
	}
}

int main() {
	init();
	compute();
	for( int i = 0; i < 10; ++i )
		std::cout << "A" << i+1 << ",B" << match[i] << std::endl;
	std::cin.get();
	return 0;
}
