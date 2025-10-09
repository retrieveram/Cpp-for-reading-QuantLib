#include <iostream>
#include <ql/time/frequency.hpp>
using namespace std;


int main(){
	QuantLib::Frequency freqSA = QuantLib::Semiannual;
	cout << "frequency:" ; cout << freqSA ;
}
