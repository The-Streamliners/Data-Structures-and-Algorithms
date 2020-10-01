// C++ program to change all char from lower to uppper
#include <iostream> 
using namespace std; 

string toLower(const string s) {
    string result = "";
    
    for (auto c : s) {
        if ((c >= 'A') && (c <= 'Z'))
            c += 32;
        result.push_back(c);
    }
    
    return result;
}


int main(int argc, const char * argv[]) {

    cout << toLower("123z!2PAaa");
    
    return 0;
}
