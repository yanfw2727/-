#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
const int D = 3;
static int count = 0;
struct unit{
    int board[3][3];
    int zx,zy,step,from,dir;
};
int transform(unit &A){
    int result = 0;
    for(int i =0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            result = result*10 + A.board[i][j];
            if(A.board[i][j]==0){
            A.zx = i;
            A.zy = j;
            }
        }
    }
    return result;
}
vector<unit>V;
int BFS(unit start){
    V.clear();
    map<int,bool>flag;
    flag[transform(start)] = true;
    start.step = 0;
    V.push_back(start);
    if(transform(start)==123456780) 
        return start.step;
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    for(int i =0;i < V.size();i++){
        unit tmp = V[i];
        for(int j=0;j<4;j++){
            int a =tmp.zx+dx[j];
            int b =tmp.zy+dy[j]; 
            if(a<0||a>D-1||b<0||b>D-1)
                continue;
            unit move = tmp;
            move.board[tmp.zx][tmp.zy] = tmp.board[a][b];
            move.board[a][b] = 0;
            if(flag[transform(move)]) 
                continue;
            flag[transform(move)] = true;
            move.step++;
            move.from = i;
            move.dir = j;
            V.push_back(move);
            if(transform(move)==123456780) 
                return move.step;
        }
    }
return -1;
}
void trace(int now){
    if(now==0) 
        return;
    trace(V[now].from);
    switch(V[now].dir){
        case 0:
        printf("u");
        count++;
        printf("%d",V[now].from);
        break;
        case 1:
        printf("d");
        count++;
        break;
        case 2:
        printf("l");
        count++;
        break;
        case 3:
        printf("r");
        count++;
        break;
    }
}
int main(){
    int num;
    unit start;
    scanf("%d",&num);
    while(num!=0){
        for(int i =0;i < D; i++){
            for(int j = 0; j < D; j++ ){
                char s[2];
                scanf("%s",s);
                if(s[0]=='x')
                    start.board[i][j] = 0;
                else
                    start.board[i][j] = atoi(s);
            }
        }
        int step = BFS(start);
        if(step == -1)
            printf("unsolvable\n");
        else{
            trace(V.size()-1);
            printf("\n");
        }
        num--;
        printf("%d", count );
    }
    system("PAUSE");
    return 0;
}
