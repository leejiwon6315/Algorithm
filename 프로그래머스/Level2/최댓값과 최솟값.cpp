#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool gg(string a, string b){
    return stoi(a) < stoi(b);
}

string solution(string s) {
    string answer = "";
    string tmp = "";
    vector<string> num;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            num.push_back(tmp);
            tmp = "";
        }
        else tmp += s[i];
    }
    num.push_back(tmp);

    sort(num.begin(), num.end(), gg);
    
    answer += num.front() + " " + num.back();
    
    return answer;
}
