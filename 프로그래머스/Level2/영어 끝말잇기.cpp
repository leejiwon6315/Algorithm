#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> check;
    stack<char> last;
    
    last.push(words[0][words[0].length()-1]);
    check.push_back(words[0]);
    
    for(int i=1; i<words.size(); i++){
        if(last.top() == words[i][0]){
            
            for(int j=0; j<check.size(); j++){
                if(words[i] == check[j]){
                    int out = i%n+1;
                    
                    if(!out) answer.push_back(n);
                    else answer.push_back(out);
                    
                    int order = i/n+1;
                    answer.push_back(order);
                        
                    return answer;
                }
            }
            last.push(words[i][words[i].length()-1]);
            check.push_back(words[i]);
        }
        else{
            int out = i%n+1;
                    
            if(!out) answer.push_back(n);
            else answer.push_back(out);
                    
            int order = i/n+1;
            answer.push_back(order);
                        
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}
