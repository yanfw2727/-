#include <iostream>

using namespace std;

int main() {
    double keep_married_rate = 0.99717;  //���B���~��O�����v 
    double no_married_rate = 0.995;      //�����B���v 
    double forever_rate;
    for(int i = 1; i < 25 ; i++){         //25�~�������󵲱B�@�������v 
        double tmp1 =(1 - (1 - no_married_rate) * 1.03)/no_married_rate;
        no_married_rate = no_married_rate * tmp1;
        cout << tmp1 << " \n";
    }
    for(int i = 1; i < 50 ; i++){       //�s��50�~�O�����B�����v 
        double tmp2 = (1 - (1 - keep_married_rate)  * 1.08)/keep_married_rate;
        keep_married_rate = keep_married_rate * tmp2;
    }
    
    forever_rate = (1 - no_married_rate) * keep_married_rate;    //�۷R�@�;��v 
    cout << forever_rate;
    cin.get();
    return 0;
}
