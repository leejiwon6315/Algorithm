#include <iostream>
#include <string>

using namespace std;
string result = "";

void reverse(string str=""){
    if(!str.size()) return;
    result += str[str.size()-1];
    str.erase(str.size()-1);
    reverse(str);
}

int main(){
    
    reverse("ABCDE");
    cout << result;
    result = "";
    return 0;
}
