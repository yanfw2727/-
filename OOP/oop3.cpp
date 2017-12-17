#include <iostream>
using namespace std;
class Amplifier {
    private :
         friend class Speaker;
       int amp ;
    public :
        Amplifier(int i = 0){
            amp = i;
        }
        
    };
class Speaker {
    private :
        int spkr;
        int comp;
    public :
        Speaker (int i = 0){
            spkr = i;
        }
        void display( ){
            if (comp > 0)
            cout << "Amplifier is greater";
            if (comp == 0)
            cout << "Impedances are matched!";
            if (comp < 0)
            cout << "Speaker is greater";
        }
        int compare(Amplifier &amp) {
            comp = amp.amp - spkr;
            return comp;
        }
    };
    int main (){
        int a = 0,b = 0;
        int &spkr = a ,&amp = b;
        cout << "請輸入Speaker Impedances:"; 
        cin >> spkr ;
        cout << "請輸入Amplifier Impedances:";
        cin >> amp ; 
        Amplifier amplifier(amp);
        Speaker speaker(spkr);
        speaker.compare(amplifier);
        speaker.display();
        
        cin.get();
        cin.get();
        return 0;
    }
