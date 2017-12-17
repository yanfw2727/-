#include <iostream> 

using namespace std;




int main(){
	string A, B;
	cout << "�п�J�r��A:\n";
	cin >> A;
	cout << "\n�п�J�r��B\n";
	cin >> B;
	int m = A.length(), n = B.length();		//���� 
	int l[m+1][n+1];							//�@���X�ӬۦP 
	int from[m+1][n+1];							//�o�I�q���� 		1=�פW��  2=��  3=�W 
	A.insert(0,"0");
	B.insert(0,"0");
	string C;
	
	
	
	for(int i =0; i <= m; i++){				//�Ĥ@��B�C�k0 
		l[i][0] = 0;
	}
	
	for(int i = 0 ; i <= n; i++){
		l[0][i] = 0;
	}
	
	for(int i = 1 ; i <= m; i++){			//�]A������ 
		for(int j = 1; j <= n ; j++){		//B
			if(A[i] == B[j]) {
				l[i][j] = l[i-1][j-1] + 1;
				from[i][j] = 1;
			}	
			else{
				if(l[i-1][j] > l[i][j-1]){
					l[i][j] = l[i-1][j];
					from[i][j] = 3;
				}
				else{
					l[i][j] = l[i][j-1];
					from[i][j] = 2;
				}
			}	
		}
	}
	
	
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n ; j++){
			cout << l[i][j] << " ";
		}
		cout << endl;
	}
	
	int b1 = m, b2 = n;										//break�I 
	int count;												//�p��c���X�Ӧr 
	
	for(int i = m; i >= 0; i--){							//back trace
		for(int j = n; j >=0 ; j--){
			if((from[i][j] == 1 && i < b1 && j < b2) || (from[i][j] == 1 &&  b1 == m && b2 == n)){
				cout << "(" << i << "," << j << ")  " ;
				cout <<l[i][j];
				cout << A[i];
				cout <<endl;
				b1 = i;
				b2 = j;
				C += A[i];
				count ++;
			}
		}
	}
	cout << "LCS �� :" ;
	for(int i = count ; i >= 0; i --){			//���X�A�� 
		cout << C[i];
	}
	
	
	return 0;
	
}
