#include <iostream>
using namespace std;

class Impedance{
   public  :
       float R;
       float X;
       Impedance(){
           R = 0;
           X = 0;
       }
       Impedance ( int r, int x ){
           R = r;
           X = x;
       }
       Impedance operator+ ( const Impedance &p ){
           Impedance tmp( R , X);
           tmp.R = this->R + p.R;
           tmp.X = this->X + p.X;
           return tmp; 
       }
        Impedance& operator = ( const Impedance &data ) { this->R = data.R; this->X = data.X; return *this; }
        Impedance operator|| ( const Impedance &p ){
            Impedance tmp ( R , X);
            float R, X;
            R = (((tmp.X * p.R + tmp.R * p.X ) * ( tmp.X + p.X )) + (( tmp.R * p.R - tmp.X * p.X ) * (tmp.R + p.R))) /((( tmp.R + p.R ) * ( tmp.R + p.R )) + (( tmp.X + p.X ) * ( tmp.X + p.X )));
            X = (((tmp.X * p.R + tmp.R * p.X ) * ( tmp.R + p.R )) - (( tmp.R * p.R - tmp.X * p.X ) * (tmp.X + p.X))) /((( tmp.R + p.R ) * ( tmp.R + p.R )) + (( tmp.X + p.X ) * ( tmp.X + p.X )));
            tmp.R = R;
            tmp.X = X;
            return tmp;
        }
        Impedance operator- () const {
            Impedance tmp(*this);
            tmp.X *= -1;
            return tmp;
        }
    };
    istream &operator>> ( istream &inst, Impedance &c ){
        cout << "Enter the active resistance: ";
        inst >> c.R;
        cout << "Enter the reactive resistance: ";
        inst >> c.X;
        return inst;
    }
    ostream &operator<< ( ostream &outst, const Impedance &c){
        outst << "Z = " << c.R << " + i * " << c.X;
        return outst;
    }
int main(){
    Impedance z1, z2, z3,zs,zp;
    int cho;
    cout << " Choose to use series or parallel. \n    If series ,input 1. \n    If parallel ,input 2. \n    If change the sign of the reactance, input 3.\nInput any key if you want to exit." << endl;
    cout << "Please input the number:";
    cin >> cho;
    while ( cho == 1 || cho == 2 || cho == 3){
    if(cho == 1){
        cin >> z1 >> z2 >> z3;
        zs=z1+z2+z3;
        cout << zs;
        break;
    }
    if(cho == 2){
        cin >> z1 >> z2 >> z3;
        zp = z1||z2||z3;
        cout << zp;
        break;
    }
    if(cho == 3){
        cin >> z1;
        z1 = -z1;
        cout << z1;
        break;
    }
    };
    cin.get();
    cin.get();
    return 0;
}
