#include <iostream>
#include <cfloat>
#include <cmath>
#include <fstream>
#include <cstdlib>
#define MAX 9999
 
 using namespace std;
 
struct Point
{
    int x, y;
};
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
float bruteForce(Point P[], int n, Point A[])
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min){
                min = dist(P[i], P[j]);
                A[0] = P[i];
                A[1] = P[j];
            }
        
    
    return min;
}
float min(float x, float y)
{
    if(x < y)
		return x;
	if(x > y)
		return y;
}
float stripClosest(Point strip[], int size, float d, Point A[])
{
    float min = d;  
 
    qsort(strip, size, sizeof(Point), compareY); 
    
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min){
                min = dist(strip[i], strip[j]);
                A[0] = strip[i];
                A[1] = strip[j];
            }
 
    return min;
}
 
float closestUtil(Point P[], int n, Point A[])
{
    if (n <= 3)
        return bruteForce(P, n, A);
 
    int mid = n/2;
    Point midPoint = P[mid];
    float dl = closestUtil(P, mid, A);
    float dr = closestUtil(P + mid, n-mid, A);
    float d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
 
    return min(d, stripClosest(strip, j, d, A) );
}
 
float closest(Point P[], int n, Point A[])
{
    qsort(P, n, sizeof(Point), compareX);
 
    return closestUtil(P, n, A);
}

void p_point(Point P[], int n){
	for(int i = 0; i < n ; i++)
		cout << "P(" <<P[i].x << ", " <<P[i].y << "), " ;
	
}
 
int main()
{
    Point P[300] ;
    int n = 0;
	ifstream fin("t3.txt");
	if(!fin){
		cout <<"ÅªÀÉ¥¢±Ñ" << endl;
		cin.get();
		cin.get();
		return 0;
	}
	fin >> n;
	for(int i = 0; i < 300; i++){
		if(i < n){
			fin >> P[i].x;
			fin >> P[i].y;
		}
		if(i >= n){
			P[i].x = MAX;
			P[i].y = MAX;
		}
	}
	Point A[2];
	float distance = closest(P, n, A);
    p_point(A, 2);
    cout << "The smallest distance is " << distance;
	fin.close();
	cin.get();
	cin.get();
    return 0;
}
