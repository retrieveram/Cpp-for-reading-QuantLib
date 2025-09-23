// p132n.cpp
#include <iostream>
#include "setXX.h"
#include "calcSum.h"
using namespace std;

int main()
{
	int * xx, sumXX;
	xx = new int[2];

	fn::setXX  ( xx        );
	fn::calcSum( xx, sumXX );
	
	cout << "*xx[0] + *xx[1] = " 
		 << sumXX << endl;
	delete [] xx;	
}
