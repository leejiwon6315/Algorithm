#include <string>
#include <vector>
#include <stack>

using namespace std;

bool correct(string s){
    stack<char> st;
    
    for(char i : s){
        if(i == '(') st.push(i);
        else if(i == ')'){
            if(st.empty()) return false;
            else st.pop();
        }
    }
    if(st.empty()) return true;
    else return false;
}

string recursion(string s){
    
    if(s == "") return s;
     
    string u = "";
    string v = "";
    int cnt1 = 0, cnt2 = 0, index = 0;
    string resultString= "";
    
    for(char i : s){
        if(i == '(') cnt1 ++;
        else cnt2 ++;
        index ++;
        
        if(cnt1 == cnt2) break;
    }
    
    u = s.substr(0,index);
    v = s.substr(index);
    
    if(correct(u)) resultString += u + recursion(v);
    else{
        resultString += '(';
        resultString += recursion(v);
        resultString += ')';
        
        u = u.substr(1,u.size()-2);
            
        for(int i: u){
            if(i == '(') resultString += ')';
            else resultString += '(';
        }
    }
    return resultString;                
}

string solution(string p) {
    string answer = "";
    
    answer = recursion(p);

    return answer;
}
