#include <iostream>
#include <ql/errors.hpp>
using namespace std;      using namespace QuantLib;

int main()
{
    int xx = -1;   // 1, 0, -1等で試すこと
  try{
    QL_REQUIRE (xx!=0,  "xx = 0");
    if(xx < 0) {QL_FAIL("xx < 0");}
    else       {cout << "xx > 0" ;}
  }
  catch(Error& e){cerr << e.what() ;}
}
