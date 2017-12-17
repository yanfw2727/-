#include <iostream>
#include <fstream>
#define MAX  500					//如要把最大上限上調，請把MAX值調大 
using namespace std;

void print(int solution[], int V);
bool hamil(bool Graph[MAX][MAX], int solution[], int n, int V);
bool safe(int v, bool Graph[MAX][MAX], int solution[], int n, int V);

int main(){
	int V;						//幾個點 
	int from[MAX];				
	int to[MAX];
	int num = 0;				//數據的數量 
	bool Graph[MAX][MAX];		//點與點之間是否有連接 
	
	ifstream fin("input4.txt");
	if(!fin){
		cout << "讀檔失敗，請重新確認檔案" <<endl;
	}
	
	fin >>V;
	for(int i = 0; i < 500; i++){
		if(fin){
			fin >> from[i];
			fin >> to[i];
			num ++;
		}
		else if(!fin){
			from[i] = 0;
			to[i] = 0;
		}
	}
	
	for(int i = 0; i < 500; i++){	//陣列初始化 
		for(int j = 0; j < 500; j++){
			Graph[i][j] = 0;
		}
	}
	
	for(int i = 0; i < num; i++){	//把數據寫入Graph 
		Graph[from[i]-1][to[i]-1] = 1;
		Graph[to[i]-1][from[i]-1] = 1;
	}

	
	int *solution = new int[V];				//設定解 
	for (int i = 0; i < V; i++){
		solution[i] = -1;
	}
	solution[0] = 0;					//設起始點為解 
	if(hamil(Graph, solution, 1, V) == false)		//從下一個點開始backtrack 
		cout << "解不存在";
	else
	print(solution, V);
	
	return 0;
}

void print (int solution[], int V){		//印出解 
	cout << "cycle:";
	for(int i = 0; i < V-1; i++){
		cout << solution[i] + 1 << "-";
	}
	cout << solution[V-1] + 1 << endl;
}

bool safe(int v, bool Graph[MAX][MAX], int solution[], int n, int V){		//確認是否可用 
	if(Graph[solution[n-1]][v] == 0)
		return false;
	for(int i = 0; i < n; i++){
		if(solution[i] == v)
			return false;
	}
	return true;
}
	
bool hamil(bool Graph[MAX][MAX], int solution[], int n, int V){				//Hamiltonian 開始 
	if(n == V){
		if(Graph[solution[n-1]][solution[0]] == 1)							//找到解 
			return true;
		else 
			return false;
	}
	
	for(int v = 1; v < V; v++){
		if(safe(v, Graph, solution, n, V)){
			solution[n] = v;
			if(hamil(Graph, solution, n+1, V) == true)
				return true;
			solution[n] = -1;
		}
	}
	return false;
}
