#include <iostream>
using namespace std;

class Temperature {
    private :
        float Temp;
        static float totTemp;
        static float times;
        static float AvgTemp;
    public  :
        Temperature () {
            Temp =  0;
        }
        void Input_Temp (float i = 0) {
            Temp = i;
        }
        void Temp_Add () {
            totTemp = totTemp + Temp;
        }
        static float Compute_Val () {
            AvgTemp = totTemp / times;
        }
        void Display () {
            cout << "本周平均溫度為:" <<AvgTemp << endl;
        }
        void Times_Add () {
            times ++;
        }
    };
    float Temperature::totTemp = 0;
    float Temperature::times = 0;
    float Temperature::AvgTemp = 0;
int main () {
    float a[7];
    char continues;
    Temperature temp[7];
    for(int i = 0; i < 7 ; i ++) {
        cout << "輸入第" << i+1 << "天溫度:"; 
        cin >> a[ i ];
        float Val = a [ i ];
        temp[ i ].Input_Temp ( Val );
        temp[ i ].Times_Add ();
        temp[ i ].Temp_Add ();
        temp[ i ].Compute_Val ();
    }
    
        temp[ 6 ].Display ();
    cin.get();
    cin.get();
    return 0;
}

