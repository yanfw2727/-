#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int cho;
    typedef vector <char> vchar;
    typedef vector <int> vint;
    stack <int> dqStack;
    stack <char, vchar> vecStack;
    stack <int, vint> veiStack;
    char ad[] = "HELLOWORLD";
    int nu[] = {1,2,3,4,5};
    cout << " Pushing the value into container..." <<endl;
    for(int i = 0; i < 11; i++){
        dqStack.push((i+1)*2);
        vecStack.push(ad[i]);
    }
    cout << "This is the thing after stack";
    while(!vecStack.empty()){
        cout << vecStack.top() << ' ';
        vecStack.pop();
        dqStack.pop();
    }
    typedef vector <double> vdou;
    queue <double, vdou> vecQueue;
    double values[5] = {1.8,2.3,7.5,5.6,4.2};
    cout << " Pushing the values into container... " << endl;
    for(int j = 0; j<5; j++){
        vecQueue.push(values[j]);
    }
    cout << "Removing values from container... " <<endl;
    cout << "This is the thing after queue" <<endl;
    while(!vecQueue.empty()){
        cout << vecQueue.front() << ' ';    
        vecQueue.pop();
    }
    cin.get();
    cin.get();
    return 0;
    }
