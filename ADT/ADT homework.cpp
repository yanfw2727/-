#include <iostream>

using namespace std;

int main() {
    double keep_married_rate = 0.99717;  //結婚後繼續保持機率 
    double no_married_rate = 0.995;      //不結婚機率 
    double forever_rate;
    for(int i = 1; i < 25 ; i++){         //25年內有任何結婚一次的機率 
        double tmp1 =(1 - (1 - no_married_rate) * 1.03)/no_married_rate;
        no_married_rate = no_married_rate * tmp1;
        cout << tmp1 << " \n";
    }
    for(int i = 1; i < 50 ; i++){       //連續50年保持結婚的機率 
        double tmp2 = (1 - (1 - keep_married_rate)  * 1.08)/keep_married_rate;
        keep_married_rate = keep_married_rate * tmp2;
    }
    
    forever_rate = (1 - no_married_rate) * keep_married_rate;    //相愛一生機率 
    cout << forever_rate;
    cin.get();
    return 0;
}
