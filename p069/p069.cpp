// p069.cpp
#include <iostream>
using namespace std;
void main()
{
	int * xx, * yy;
	xx = new int    ;       yy = new int;	
	cout << "*xx は "; 	    cin >> *xx  ;
	cout << "*yy = "; 	    cin >> *yy  ;
	cout << "*xx + *yy = "  
					<< *xx + *yy << endl;
	delete xx; 	            delete yy   ; 
}
