#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int *a, int *b);
void quick_sort(int *data, int left, int right, double &comp, double &chg);
int main(){
    clock_t start, stop;
    double num_comp = 0.0, num_chg = 0.0;
    double num_compa[100], num_chga[100];
    int rand_num[500000];                           //�`�@�ƾ� 
    double cnt_com[100], cnt_chg[100], u_time[100]; //com=compare times   chg = change times  utime = using time
     for(int cnt = 0; cnt < 100; cnt++){        //����100�� 
     num_comp = 0.0;
     num_chg = 0.0;
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
        start = clock();                            //�p�ɶ}�l 
        
        quick_sort(rand_num, 0, 499999, num_comp, num_chg);
        stop = clock();                             //�p�ɵ��� 
        num_compa[cnt] = num_comp;
        cout << cnt+1 << "��" <<endl; 
        cout << "Compare :" << num_compa[cnt] << "times" << endl;
        num_chga[cnt] = num_chg;
        cout << "Change :" << num_chga[cnt] << "times" << endl;
        u_time[cnt] = double(stop - start)/CLOCKS_PER_SEC;
        cout <<"Using :" <<u_time[cnt]<<endl;
        cout << "===========================" << endl;
    }
    double total_time = 0;
    double total_comp = 0;
    double total_chg = 0;
    for(int cnt = 0; cnt < 100; cnt++){
        total_time = total_time + u_time[cnt];
        total_comp = total_comp + num_compa[cnt];
        total_chg = total_chg + num_chga[cnt];
    }
    double ave_time = total_time / 100;
    double ave_comp = total_comp / 100;
    double ave_chg = total_chg / 100;
        cout << "ave compare is :" << ave_comp;
        cout << "ave change is :" << ave_chg;
        cout << "ave time is :" << ave_time;
    cin.get();
    cin.get();
    return 0;
}
         
void quick_sort(int *data, int left, int right, double &comp, double &chg)
{
    int pivot, i , j;
    if(left < right) {
            
        pivot = data[(left+right)/2];
        i = left - 1;
        j = right + 1;
        while (i < j){
            do{
                comp++;
                ++i;
            }while(data[i] < pivot);
            do{
                comp++;
                --j;
            }while(data[j] > pivot);
            if(i < j){
            swap(&data[i], &data[j]);
                chg++;
            }
        }
        quick_sort(data, left, i-1, comp, chg);
        quick_sort(data, j+1, right, comp, chg);
     }
}        

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
