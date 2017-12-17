
#include <iostream>

using namespace std;

class CaseBox{
	public:
		double m_L;
		double m_W;
		double m_H;
		
		CaseBox(double lv,double wv, double hv){
			cout << endl <<"calling constructor";

			m_L=lv;
			m_W=wv;
			m_H=hv;
		}

	double Area(){
		return 2.0*(m_L*m_W+m_W*m_H+m_L*m_H);
	}
};
int main(){
	CaseBox S1(19.3,75.6,27.9);
	CaseBox S2(18.3,74.6,26.9);
	double area1 = 0.0;
	double area2 = 0.0;
	
	
	area1=S1.Area();
	area2=S2.Area();
	cout <<endl
		<<"S1area=" <<area1
		  				 <<"(cm)2";
	
	cout <<endl
	      <<"S2area=" <<area2
		  				 <<"(cm)2"; 
	
	cout <<endl
	       <<"a CaseBox object use" <<sizeof S1<< " byte\n"; 
	       
	cout <<endl;
	system("pause");
	return 0;
}