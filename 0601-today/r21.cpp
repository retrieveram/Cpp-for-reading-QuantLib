#include <iostream>
#include <ql/quantlib.hpp>
using namespace std;      using namespace QuantLib;

void main(){
	
	Date todayDT = Settings::instance().evaluationDate();
	cout << "Today:"       << todayDT ;

	Settings::instance().evaluationDate() = Date(28,April,2025);
	cout << ",  New Date:" << Settings::instance().evaluationDate();
}
