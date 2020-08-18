#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sizeSort(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    bool visit[100001] = {false, };
    vector<int> answer;
    vector<int> tupleNum;
    vector<vector<int>> numbers;
    
    string num = "";
    
    for(int i=1; i<s.size()-1; i++){
        if(s[i] == '{') continue;
        
        if(s[i] == '}'){
            tupleNum.push_back(atoi(num.c_str()));
            num = "";
            numbers.push_back(tupleNum);
            tupleNum.clear();
            i++;
        }
        
        else if(s[i] == ','){
            tupleNum.push_back(atoi(num.c_str()));
            num = "";
        }
        else{
            num += s[i];
        }
    }
   
    sort(numbers.begin(), numbers.end(), sizeSort);
    
    for(int i=0; i<numbers.size(); i++){
        sort(numbers[i].begin(), numbers[i].end());
    }
    
    answer.push_back(numbers[0][0]);
    
    for(int i=1; i<numbers.size(); i++){
        int j=0;
        for(j=0; j<numbers[i-1].size(); j++){
            if(numbers[i-1][j] != numbers[i][j]){
                answer.push_back(numbers[i][j]);
                break;
            }
        }
        if(j == numbers[i-1].size()){
            answer.push_back(numbers[i].back());
        }
    }
    
    return answer;
}
