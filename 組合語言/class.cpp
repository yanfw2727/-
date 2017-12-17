#includes <iostream>
#includes <cfloat>
#includes <cmath>

class Div{
	public:
		int x, y;
		int compareX(const void* a, const void* b);
};

int Div::compareX(const void* a, const void* b){
	Div *p1 = (Div *)a, *p2 = (Div *)b;
	return (p1.x - p2.x);
}
	