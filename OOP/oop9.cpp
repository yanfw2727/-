#include <iostream>
using namespace std;

class Vehicle {
    public   :
        virtual void SetData( double Capacity, double Consumption ,double Dis) = 0;
        virtual double ReachedRange()  = 0; // distance can drived with full tank 
        virtual double RefuelTimes( double dis )  = 0; // least refules times needed
        virtual void display () = 0; // display the data
    protected:
        double cap; // fuel tank
        double con; // use per  km
};
class Car :   public Vehicle{
    public   :
        double dis;
        int time;
        Car( ) {
            cap = 0;
            con = 0;
            time = 0;
        }
        void SetData( double Capacity, double Consumption,double Dis ){
            cap = Capacity; 
            con = Consumption;
            dis = Dis;
            time ++;
        }
        
        double ReachedRange() {
            double len;
            len = cap / con;
            return len;
        }
        double RefuelTimes( double dis ) {
            double times;
            double len;
            len = cap / con;
            times = dis / len;
            if(times == int(times)){
                return times;
            }
            if(times != int(times)){
                return int (times)+1;
            }
        }
        void display(){
            cout << "car's capacity is " <<cap << endl;
            cout << "car's consumption is " << con << endl;
            cout << "car can run "<< ReachedRange() << "KM" << endl;
            cout << "car should add " << RefuelTimes( dis ) << " oil" << endl;
            cout << "car have been called " << time << " times" << endl;
        }
    };
class Truck :   public Vehicle{
    public   :
        double dis;
        int time;
        Truck( ) {
            cap = 0;
            con = 0;
            time = 0;
        }
        void SetData( double Capacity, double Consumption ,double Dis){
            cap = Capacity; 
            con = Consumption;
            time ++;
            dis = Dis;
        }
        
        double ReachedRange() {
            double len;
            len = cap / con;
            return len;
        }
        double RefuelTimes( double dis ) {
            double times;
            double len;
            len = cap / con;
            times = dis / len;
            if(times == int(times)){
                return times;
            }
            if(times != int(times)){
                return int (times)+1;
            }
        }
        void display(){
            cout << "truck's capacity is " <<cap << endl;
            cout << "truck's consumption is " << con << endl;
            cout << "truck can run "<< ReachedRange() << "KM" << endl;
            cout << "truck should add " << RefuelTimes( dis ) << " oil" << endl;
            cout << "truck have been called " << time << " times" << endl;
        }
    };
    int main (){
        double c_cap, c_con, t_cap, t_con, dis;
        cout << "Please input car's Capacity and Consumption: " << endl;
        cin >> c_cap >> c_con;
        cout << "Please input truck's Capacity and Consumption: " << endl;
        cin >> t_cap >> t_con;
        cout << "Please input the distance : "<< endl;
        cin >> dis;
        
        Vehicle *ptr;
        
        
        ptr = new Car;
        ptr ->SetData( c_cap, c_con, dis);
        ptr ->RefuelTimes( dis );
        ptr ->display();
        delete ptr;
        
        
        ptr = new Truck;
        ptr ->SetData( t_cap, t_con, dis);
        ptr ->RefuelTimes( dis );
        ptr ->display();
        delete ptr;
        
        
        cin.get();
        cin.get();
        return 0;
    }
