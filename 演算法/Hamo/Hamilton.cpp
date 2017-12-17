#include <iostream>
#include <fstream>
#define MAX  500					//�p�n��̤j�W���W�աA�Ч�MAX�Ƚդj 
using namespace std;

void print(int solution[], int V);
bool hamil(bool Graph[MAX][MAX], int solution[], int n, int V);
bool safe(int v, bool Graph[MAX][MAX], int solution[], int n, int V);

int main(){
	int V;						//�X���I 
	int from[MAX];				
	int to[MAX];
	int num = 0;				//�ƾڪ��ƶq 
	bool Graph[MAX][MAX];		//�I�P�I�����O�_���s�� 
	
	ifstream fin("input4.txt");
	if(!fin){
		cout << "Ū�ɥ��ѡA�Э��s�T�{�ɮ�" <<endl;
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
	
	for(int i = 0; i < 500; i++){	//�}�C��l�� 
		for(int j = 0; j < 500; j++){
			Graph[i][j] = 0;
		}
	}
	
	for(int i = 0; i < num; i++){	//��ƾڼg�JGraph 
		Graph[from[i]-1][to[i]-1] = 1;
		Graph[to[i]-1][from[i]-1] = 1;
	}

	
	int *solution = new int[V];				//�]�w�� 
	for (int i = 0; i < V; i++){
		solution[i] = -1;
	}
	solution[0] = 0;					//�]�_�l�I���� 
	if(hamil(Graph, solution, 1, V) == false)		//�q�U�@���I�}�lbacktrack 
		cout << "�Ѥ��s�b";
	else
	print(solution, V);
	
	return 0;
}

void print (int solution[], int V){		//�L�X�� 
	cout << "cycle:";
	for(int i = 0; i < V-1; i++){
		cout << solution[i] + 1 << "-";
	}
	cout << solution[V-1] + 1 << endl;
}

bool safe(int v, bool Graph[MAX][MAX], int solution[], int n, int V){		//�T�{�O�_�i�� 
	if(Graph[solution[n-1]][v] == 0)
		return false;
	for(int i = 0; i < n; i++){
		if(solution[i] == v)
			return false;
	}
	return true;
}
	
bool hamil(bool Graph[MAX][MAX], int solution[], int n, int V){				//Hamiltonian �}�l 
	if(n == V){
		if(Graph[solution[n-1]][solution[0]] == 1)							//���� 
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
