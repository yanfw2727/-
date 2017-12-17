#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

static int count = 0 , wcount = 0;
struct node{                                        // 建造一個node的型態 
    int array[3][3];
    int zero_x, zero_y, step, from, to;
};
int change(node &N){                                //result 將整個九宮格數字轉成一整排的數字 
    int result = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            result = result * 10 + N.array[i][j];
            if(N.array[i][j] == 0){                 //將零的位置傳到node中 
                N.zero_x = i;
                N.zero_y = j;
            }
        }
    }
    return result;
}

vector<node> N;                                     //建立一個container 
int BFS( node start){                               //將整個程式做BFS 
    map<int,bool>flag;
    flag[change(start)] = true;
    start.step = 0;
    N.push_back(start);
    if(change(start) == 123456780) 
        return start.step;
    int tran_zero_x[4] = {1, -1, 0 ,0};
    int tran_zero_y[4] = {0, 0, 1, -1};
    for(int i = 0; i  < N.size(); i++){
        node temp = N[i];
        for(int j = 0; j < 4; j++){
            int a = temp.zero_x + tran_zero_x[j];
            int b = temp.zero_y + tran_zero_y[j];
            if( a < 0|| a > 2 || b < 0 || b > 2)
                continue;
            node move = temp ; 
            move.array [temp.zero_x][temp.zero_y] = temp.array[a][b];
            move.array[a][b] = 0;
            if(flag[change(move)])
                continue;
            flag[change(move)] = true;
            move.step++;
            move.from = i;
            move.to = j;
            N.push_back(move);
            if(change(move) == 123456780)
                return move.step;
        }
    }
    return -1;
}
vector<node> V;                                     //建造一個給只能排出錯誤方法的container 
int inverseBFS( node start){                        //無法正確排列的BFS 
    map<int,bool>flag;
    flag[change(start)] = true;
    start.step = 0;
    V.push_back(start);
    if(change(start) == 123456870) 
        return start.step;
    int tran_zero_x[4] = {1, -1, 0 ,0};
    int tran_zero_y[4] = {0, 0, 1, -1};
    for(int i = 0; i  < V.size(); i++){
        node temp = V[i];
        for(int j = 0; j < 4; j++){
            int a = temp.zero_x + tran_zero_x[j];
            int b = temp.zero_y + tran_zero_y[j];
            if( a < 0|| a > 2 || b < 0 || b > 2)
                continue;
            node move = temp ; 
            move.array [temp.zero_x][temp.zero_y] = temp.array[a][b];
            move.array[a][b] = 0;
            if(flag[change(move)])
                continue;
            flag[change(move)] = true;
            move.step++;
            move.from = i;
            move.to = j;
            V.push_back(move);
            if(change(move) == 123456870)
                return move.step;
        }
    }
    return -1;
}
void inverseprocess(int now){                        //無法正確排列時的過程九宮格 
    if(now == 0)
        return;
    inverseprocess(V[now].from);
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            cout << V[now].array[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}
void process(int now){                              //正確排列時的過程九宮格 
    if(now == 0)
        return;
    process(N[now].from);
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            cout << N[now].array[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}
void inversetrace(int now){                         //無法正確排列時的移動方向 
    if(now == 0)
        return;
    inversetrace(V[now].from);
    switch(V[now].to){
        case 0:
        cout << "U";
        wcount++;
        break;
        
        case 1:
        cout << "D";
        wcount++;
        break;
        
        case 2:
        cout << "L";
        wcount++;
        break;
        
        case 3:
        cout << "R";
        wcount++;
        break;
    }
    if(wcount % 5 == 0){
        cout << " ";
    }
}
void trace(int now){                                 //正確排列時的移動方向 
    if(now == 0)
        return;
    trace(N[now].from);
    switch(N[now].to){
        case 0:
        cout << "U";
        count++;
        break;
        
        case 1:
        cout << "D";
        count++;
        break;
        
        case 2:
        cout << "L";
        count++;
        break;
        
        case 3:
        cout << "R";
        count++;
        break;
    }
    if(count % 5 == 0){
        cout << " ";
    }
}
int main(){                                         //主函式 
    node start;
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            int num;
            cin >> num;
            start.array[i][j] = num;
        }
    }
    int step = BFS(start);                          //讓step判斷是否可以正確排列 
    if(step != -1){                                 //可正確排列 
        cout << endl;
        trace(N.size()-1);
        cout << endl;
        cout << "success,移動最小次數為: "  << count;
        cout << endl << endl;
        process(N.size()-1);
        cout << endl;
    }  
        
    else{                                           //無法正確排列 
        int wrong_step = inverseBFS(start);
        inversetrace(V.size()-1);
        cout << endl;
        cout << "fail,移動最小次數為: " <<  wcount;
        cout << endl << endl;
        inverseprocess(V.size()-1);
        cout << endl;
    }
    system("PAUSE");
    return 0;
}
