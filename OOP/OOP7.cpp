#include <iostream>
using namespace std; 

class Circuit {
    protected : //Data member
    double vol;
    double cur;
    double res;
    
    public    : //Functions
    Circuit() {
        vol = 0.0;
        cur = 0.0;
        res = 0.0;
    }
    void  Input() {
        cout << "請輸入電壓:";
        cin >>  vol;
        cout << "請輸入電阻:";
        cin >>  res;
    }
    double  Compute() {
        cur = vol / res ;
        return cur;
    }
    void display() {
        cout << "input電壓為: " << vol << endl; 
        cout << "input電流為: " << cur << endl;
    }
};
class Amplifier : protected Circuit {
    protected   : //Data member
    double gain; 
    double ovol;
    double ocur;
    public      : //constructor
    Amplifier () {
        vol = 0.0;
        cur = 0.0;
        res = 0.0;
        gain = 0.0;
        ovol = 0.0;
        ocur = 0.0;
    }
    public      : //Functions
    void Input() {
         this -> Circuit :: Input ();
        }
    double Compute() {
         this -> Circuit :: Compute() ;
         ovol = gain * vol;
         ocur = ovol / res;
         return ovol;
        }
    void display() {
        this -> Circuit :: display() ;
        cout << "output電壓為: " << ovol << endl;
        cout << "output電流為: " << ocur << endl; 
        cout << "電阻為: " << res << endl;
        cout << "gain為: " << gain << endl; 
    }
    double get( double a ){ 
    gain = a;
    return gain; }
};
int main (){
    Amplifier A;
    double gain;
    cout << "請輸入gain值";
    cin >> gain; 
    A.Input();
    A.get(gain) ;
    A.Compute(); 
    A.display();
    cin.get();
    cin.get();
    return 0 ;
} 
