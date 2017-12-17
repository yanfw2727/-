#include <iostream>
#include <cstdlib>
using namespace std;
void insertion_sort(int *data, int n);
int main(){
    int test[10];
    for(int i = 0; i < 10 ; i ++){
        test[i] = rand()%10;
    }
    insertion_sort(test, 10);
    
    for(int i = 0; i< 10; i++){
        cout << test[i] << endl;
    }
    
    cin.get();
    cin.get();
    return 0;
}
void insertion_sort(int *data, int n){
    for(int i = 2; i <= n; ++i){
        int pivot = data[i];
        
        int j;
        for(j = i - 1; j>= 0; --j)
            if(pivot < data[i])
                data[j+1] = data[j];
            else 
                break;
        
        data[j+1] = pivot;
    }
}
