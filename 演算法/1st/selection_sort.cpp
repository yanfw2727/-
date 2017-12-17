#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void swap(int *a, int *b);
void selection_sort(int *a, int n, double &comp, double &chg, double &flag);
int main(){
    clock_t start, stop;
    double num_comp = 0.0, num_chg = 0.0, num_flag = 0.0;
    double num_compa[100], num_chga[100], num_flaga[100];
    int rand_num[500000];                           //總共數據 
    double cnt_com[100], cnt_chg[100], u_time[100]; //com=compare times   chg = change times  utime = using time
     for(int cnt = 0; cnt < 100; cnt++){        //執行100次 
     num_comp = 0.0;
     num_chg = 0.0;
     num_flag = 0.0;
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
        start = clock();                            //計時開始 
        
        selection_sort(rand_num, 500000, num_comp, num_chg, num_flag);
        stop = clock();                             //計時結束
        cout << cnt+1 << "次" <<endl; 
        num_compa[cnt] = num_comp; 
        cout << "Compare :" << num_compa[cnt] << "times" << endl;
        num_chga[cnt] = num_chg;
        cout << "Change :" << num_chga[cnt] << "times" << endl;
		num_flaga[cnt] = num_flag;
        cout << "flag :" << num_flaga[cnt] << "times" << endl;
        u_time[cnt] = double(stop - start)/CLOCKS_PER_SEC;
        cout <<"Using :" <<u_time[cnt]<<endl;
        cout << "===========================" << endl;
    }
    double total_time = 0.0;
    double total_comp = 0.0;
    double total_chg = 0.0;
    double total_flag = 0.0;
    for(int cnt = 0; cnt < 100; cnt++){
        total_time = total_time + u_time[cnt];
        total_comp = total_comp + num_compa[cnt];
        total_chg = total_chg + num_chga[cnt];
        total_flag = total_flag + num_flaga[cnt];
    }
    double ave_time = total_time / 100;
    double ave_comp = total_comp / 100;
    double ave_chg = total_chg / 100;
    double ave_flag = total_flag / 100;
        cout << "ave compare is :" << ave_comp << endl;
        cout << "ave change is :" << ave_chg<<endl;
        cout << "ave flag is :" << ave_flag<<endl;
        cout << "ave time is :" << ave_time<<endl;
    cin.get();
    cin.get();
    return 0;
}

void selection_sort(int *a, int n, double &comp, double &chg, double &flag){
    for(int i = 0; i < n; i++){
        int index = i;
        flag++;
        for(int j = i + 1; j < n ; j++){
        	comp++;
            if(a[j] < a[index]){
                index = j;
                flag++;
            }
        }
        swap(a[i], a[index]);
        chg++;
    }
} 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
