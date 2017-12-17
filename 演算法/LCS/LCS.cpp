#include <iostream> 

using namespace std;




int main(){
	string A, B;
	cout << "請輸入字串A:\n";
	cin >> A;
	cout << "\n請輸入字串B\n";
	cin >> B;
	int m = A.length(), n = B.length();		//長度 
	int l[m+1][n+1];							//共有幾個相同 
	int from[m+1][n+1];							//這點從哪來 		1=斜上方  2=左  3=上 
	A.insert(0,"0");
	B.insert(0,"0");
	string C;
	
	
	
	for(int i =0; i <= m; i++){				//第一行、列歸0 
		l[i][0] = 0;
	}
	
	for(int i = 0 ; i <= n; i++){
		l[0][i] = 0;
	}
	
	for(int i = 1 ; i <= m; i++){			//跑A的長度 
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
	
	int b1 = m, b2 = n;										//break點 
	int count;												//計算c有幾個字 
	
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
	cout << "LCS 為 :" ;
	for(int i = count ; i >= 0; i --){			//把輸出顛倒 
		cout << C[i];
	}
	
	
	return 0;
	
}
