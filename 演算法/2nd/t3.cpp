 #include <iostream>
#include <cstdlib>
#include <fstream>
#define MAX 99
using namespace std;
struct node {
    int fr, to, cost;
}p[4];
int c = 0, temp1 = 0, temp = 0;
void prims(int *is_sel, int Matrix[][5], int i, int j){
    is_sel[i] = 1;
    while (c < 4){
        int min = 999;
        for (int i = 0; i < 5; i++){
            if (is_sel[i] == 1){
                for (int j = 0; j < 5; ){
                    if (Matrix[i][j] >= min || Matrix[i][j] == 0)
                    {
                        j++;
                    }
                    else if (Matrix[i][j] < min)
                    {
                        min = Matrix[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        is_sel[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;       
        Matrix[temp][temp1] = Matrix[temp1][temp]=1000;
    }
    for (int k = 0; k < 4; k++){
        cout<<"source node:"<<p[k].fr + 1 <<endl;
        cout<<"destination node:"<<p[k].to + 1<<endl;
        cout<<"weight of node:"<<p[k].cost<<endl;
        cout<<"================\n" << endl;
    }
}

void dijk(int point, int sel_matrix, int Matrix[5][5], int dist[]){
	int u,count, flag[5], min;
	for(int i = 0; i < point; i++){
		flag[i] = 0;
		dist[i] = Matrix[sel_matrix][i];
	}
	count = 2;
	while(count <= point){
		min = 50;
		for(int j = 0; j < point; j++){
			if(dist[j] < min && !flag[j]){
				min = dist[j];
				u = j;
			} 
		}
		flag[u] = 1;
		count++;
		for(int j = 0; j < point; j++){
			if((dist[u] + Matrix[u][j] < dist[j]) && !flag[j]){
				dist[j] = dist[u] + Matrix[u][j];
			}
		}
	}
}

int main(){
	int point = 0;              //���X��node
	int start[20],end[20], length[20];//��B����
	int num = 0;                //���h�ֲռƾ�
	ifstream fin("t2.txt");
	if(!fin){
		cout <<"Ū�ɥ���" << endl;
		cin.get();
		cin.get();
		return 0;
	}
	fin >> point;

	for(int i = 0 ; i < 20; i ++){  //�s�J�ƭȨðO�����h�ֲռƾ�
	    if(fin){
	        fin>>start[i];
			fin >>end[i];
			fin >>length[i];
			num++;
	    }
	    else if(!fin){
	        start[i] = 0;
	        end[i] = 0;
	        length[i] = 0;
	    }
	}
    num = num - 1 ;
	int is_sel[point];                  //�ݬO�_�Q���
	int Matrix[5][5];          	 		//��Ӱ}�C
	int Matrix_backup[5][5];			//�N�}�C�ƥ��@���A�]��Prim������|�ܰ� 
	for(int i = 0; i < point; i++){     //�NMatrix��l��
	    for(int j = 0; j < point; j++){
	        Matrix[i][j] = 0;
	    }
	}
	
	for(int i = 0 ; i < point; i++){   //�N�Q����˩w��l��
	    is_sel[i] = 0;
	}
	
	for(int i = 0; i < num; i ++){      //�N�e�����ƭȿ�JMatrix
	    Matrix[start[i]-1][end[i]-1] = length[i];
	    Matrix[end[i]-1][start[i]-1] = length[i];
	}
	
    for(int i = 0; i < point; i++){     //�NMatrix�ƥ� 
	    for(int j = 0; j < point; j++){
	        Matrix_backup[i][j] = Matrix[i][j];
	    }
	}
    prims(is_sel, Matrix, 0, 0);		//prim����
	
										//Dijk�}�l 
	cout << endl <<endl;
	for(int i = 0; i < point; i++){     //�NMatrix�٭� 
	    for(int j = 0; j < point; j++){
	        Matrix[i][j] = Matrix_backup[i][j];
	    }
	}
	
	int dist[5];						//�Z�� 
	int sel_matrix;						//�Q��ܪ�point 
	
	for(int i = 0; i < point; i ++){ 		//�NMatrix��0�ܦ^���j��
		for(int j = 0; j < point; j++){
			if(Matrix[i][j] == 0){
				Matrix[i][j] = MAX;
			}
		} 
	}
	
	sel_matrix = 0;						//�̷��D�N��ܲĤ@���I
	dijk(point, sel_matrix, Matrix, dist);
	cout <<"shortest path: \n" ;
	for(int i = 0; i < point ; i++){
		if(i != sel_matrix){
			cout << sel_matrix + 1 <<"->" << i + 1 << ", length = " << dist[i] << "\n";
		}
	}
	
	fin.close();
	cin.get();
	cin.get();
	return 0;
}
