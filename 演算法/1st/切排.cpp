#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    clock_t start, stop;
    int rand_num[500000];                           //�`�@�ƾ� 
    double cnt_com[100], cnt_chg[100], u_time[100]; //com=compare times   chg = change times  utime = using time
//����100�� 
        for(int i = 0; i < 500000 ; i++){       //�N1~50W���Ʀr��J 
            rand_num[i] = i;
        }
        time_t using_time;
        srand((unsigned)time(NULL));    
        
        for(int test_time = 0; test_time < 10000000; test_time++){      //���ƺt��k 
            int num1=(rand()*rand()+rand())%500000;
            int num2=(rand()*rand()+rand())%500000;
            
            swap(rand_num[num1], rand_num[num2]);
        }
        for(int i = 0; i < 500000 ; i++){
            cout << rand_num[i] << endl;
        } 
    
    cin.get();
    cin.get();
    return 0;
}
