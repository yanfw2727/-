#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
struct node {
    int fr, to, cost;
}p[4];
int c = 0, temp1 = 0, temp = 0;
void prims(int *a, int b[][5], int i, int j)
{
    a[i] = 1;
    while (c < 4)
    {
        int min = 999;
        for (int i = 0; i < 5; i++)
        {
            if (a[i] == 1)
            {
                for (int j = 0; j < 5; )
                {
                    if (b[i][j] >= min || b[i][j] == 0)
                    {
                        j++;
                    }
                    else if (b[i][j] < min)
                    {
                        min = b[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        a[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;       
        b[temp][temp1] = b[temp1][temp]=1000;
    }
    for (int k = 0; k < 4; k++)
    {
        cout<<"source node:"<<p[k].fr + 1 <<endl;
        cout<<"destination node:"<<p[k].to + 1<<endl;
        cout<<"weight of node:"<<p[k].cost<<endl;
    }
}


int main(){
	int point = 0;              //���X��node
	int start[20],end[20], length[20];//��B����
	int num = 0;                //���h�ֲռƾ�
	ifstream fin("t2.txt");
	if(!fin){
		cout <<"Ū�ɥ���" << endl;
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
	int is_sel[5];                  //�ݬO�_�Q���
	int Matrix[5][5];           //��Ӱ}�C
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
    
    prims(is_sel, Matrix, 0, 0);
	
	fin.close();
	return 0;
}
