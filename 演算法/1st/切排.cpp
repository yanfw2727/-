#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    clock_t start, stop;
    int rand_num[500000];                           //總共數據 
    double cnt_com[100], cnt_chg[100], u_time[100]; //com=compare times   chg = change times  utime = using time
//執行100次 
        for(int i = 0; i < 500000 ; i++){       //將1~50W的數字輸入 
            rand_num[i] = i;
        }
        time_t using_time;
        srand((unsigned)time(NULL));    
        
        for(int test_time = 0; test_time < 10000000; test_time++){      //切排演算法 
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
