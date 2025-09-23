// p132b.cpp
#include <iostream>
#include "calcSum.h"
using namespace std;

int main()
{
	int * xx, sumXX;
	xx = new int[2];
	cout << "xx[0] = "; cin >> xx[0];
	cout << "xx[1] = "; cin >> xx[1];
	
	calcSum( xx, sumXX );

	cout << "xx[0] + xx[1] = " 
		 << sumXX  << endl;
	delete [] xx;	return 0;
}
