#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool p(int a, int b){
    return a<b;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    
    for(int j = 0; j<commands.size(); j++){
        for(int i=commands[j][0]-1; i<=commands[j][1]-1; i++){
           tmp.push_back(array[i]);
        }
        sort(tmp.begin(),tmp.end(), p);
        //p대신 greater<int>() 사용이 가능할듯
        
        answer.push_back(tmp[(commands[j][2]-1)]);
        
        tmp.clear();
    }
    return answer;
}
