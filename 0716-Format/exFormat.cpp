#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define QL_ERROR_LINES   // シンボル定義

string format(
    #ifdef QL_ERROR_LINES
        const string& file, long line,
    #else
        const string&,      long,
    #endif
    const string& message            
    ) 
    { 
    ostringstream msg;
    #ifdef QL_ERROR_LINES
        msg << file << " (" << line << "): ";
    #endif
    msg << message;
    return msg.str();
    }

int main() {
    string rslt = format("fileABC.cpp", 10, "Error happened!");
    cout << rslt;
}
