#include <iostream>

#include <ql/time/period.hpp>
using namespace std;      using namespace QuantLib;

int main() {
  try{	
	Period pd2w(2,Weeks), pd6m(Semiannual);
	cout <<     "A)pd2w:"         << pd2w;
	cout << ",     .length():"    << pd2w.length();
	cout << ",     .units():"     << pd2w.units();
	cout << ",     .frequency():" << pd2w.frequency() << endl;

	cout <<     "B)pd6m*2:"       << pd6m*2;
	cout << ",   C)2*Weeks:"      << 2*Weeks;
	cout << ",   D)years(pd6m):"  << years(pd6m);
	// years(pd2w)はエラー処理へ
	cout << ",   E)years(pd2w):"  << years(pd2w);	
  }
  catch (std::exception& e) {cerr << e.what(); }   
}