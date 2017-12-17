#include <iostream>
#include <fstream>

using namespace std;

int main () {
    int A[10][10],B[10][10],test = 0,temp[10],val=0;
    char a;
    ifstream fin("T15.txt");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <=10; j++){
            fin >> a;
            fin >> A[i][j];
    }}
    for(int i = 0; i <10; i++){
        for(int j = 0; j <=10; j++){
            fin >> a;
            fin >> B[i][j];
    }}
    for(int i = 0; i < 10; i++){
        for(int j = 1; j <=10; j++){
            test = A[i][j];
            temp[val] = i+1;
            val++;
            for(int k = 0; k< 10 ; k++){
                if(test == A[k][j] && k!=i){
                    temp[val] = k+1;
                }
            }
            for(int k = 1; k <= 10; k++){
                for (int m = 0; m < 10; m ++){
                if(B[test][k] = temp[m]){
                cout << "A" << temp[m] << ",B" << B[test][0] <<endl;
                break;
                break;
            }
            }
        }
    }
        }         
               
    cin.get();
    cin.get();
    return 0;
}
            
