
#include <iostream>
#include <ql/time/date.hpp>
using namespace std;        using namespace QuantLib;

int main(){
	
	Date        todayDT     =  Date(28,April,2025);
	Weekday     todayWD     =  todayDT.weekday()  ;
	
	cout <<    "A)Weekday:" << todayWD            ;
	cout <<",   B)todayWDの値:" 
		   << static_cast<int>(todayWD) << endl   ; 
	
	cout <<     "C)long:"    << io::long_weekday    (todayWD);
	cout << ",   D)short:"   << io::short_weekday   (todayWD);
	cout << ",   E)shortest:"<< io::shortest_weekday(todayWD);
}
