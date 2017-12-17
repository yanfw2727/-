#include <iostream>
using namespace std;

class Resistor{    //  subclass
    private  :
        double res;
    public   :
        Resistor(){
            res = 0;
        }
        Resistor(double r){
            res = r;
        }
        virtual ~Resistor(){
            cout <<" Resistor is destoryed! ";
        }
        
        friend ostream &operator << ( ostream &outst, const Resistor &r);
        
    };
 ostream &operator<< ( ostream &outst, const Resistor &r){
            outst << "resistance = " << r.res << "£[" << endl;
            return outst;
        }
class Circuit{  // compsed class
    private  :
        double cur;
        double vol;
    public   :
        
        Resistor r;
        Circuit( double v, double res ): r( res ) { 
            cur = v / res ;
            vol = v;
            }
        virtual ~Circuit (){
            cout << " Circuit is destroyed! ";
        }
    friend ostream &operator << ( ostream &outst, const Circuit &c);
    };
    ostream &operator<< ( ostream &outst, const Circuit &c){
            outst << "Current = " << c.cur << endl;
            outst << "Voltage = " << c.vol ;
            return outst;
        }
    int main() {
        double res, vol;
        cout << "Please input resistance: " << endl;
        cin >> res;
        cout << "Please input voltage: " << endl;
        cin >> vol;
        Circuit c( vol, res );
        cout << c.r;
        cout << c;
        cin.get();
        cin.get();
        return 0;
    }
        
