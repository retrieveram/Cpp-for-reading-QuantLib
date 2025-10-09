#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
int main()
{
    int xx = 0;   // 1, 0, -1等で試すこと
  try{
    if(xx == 0) {throw string       ("xx = 0");}
    if(xx <  0) {throw runtime_error("xx < 0");}		
    else        {throw               "xx > 0" ;}
  }
  catch(string&    strg){cerr << strg       ;}
  catch(exception& rter){cerr << rter.what();}	  
  catch(...)         {cerr << "char* xx > 0";}
}
