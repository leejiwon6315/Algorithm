#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int, vector<int>, less<int>> maxQ;
    
    for(string i : operations){
        if(i[0] == 'I'){
            i.erase(i.begin(), i.begin()+1);
            maxQ.push(stoi(i));
            minQ.push(stoi(i));
        }
        else if(i == "D 1" && !maxQ.empty()){
            maxQ.pop();
        }
        else if(i == "D -1" && !minQ.empty()){
            minQ.pop();
        } 
    }
    
    vector<int> tmp;
    vector<int> tmpAnswer;
    
    while(!maxQ.empty()){
        tmp.push_back(maxQ.top());
        maxQ.pop();
    }
    while(!minQ.empty()){
        tmp.push_back(minQ.top());
        minQ.pop();
    }
    
    sort(tmp.begin(), tmp.end());
    
    for(int i=1; i<tmp.size(); i++){
        if(tmp[i] == tmp[i-1]){
            tmpAnswer.push_back(tmp[i]);
        }
    }
    
    if(tmpAnswer.empty()) answer={0, 0};
    else{
        sort(tmpAnswer.begin(), tmpAnswer.end());
        answer.push_back(tmpAnswer[tmpAnswer.size()-1]);
        answer.push_back(tmpAnswer[0]);
    }
    return answer;
}
