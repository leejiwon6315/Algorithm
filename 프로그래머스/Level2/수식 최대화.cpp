#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> expLocation, exp;
    string number;
    
    for(int i=0; i<expression.size(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            num.push_back(stoi(number));
            number = "";
            if(find(exp.begin(), exp.end(), expression[i]) == exp.end()){
                exp.push_back(expression[i]);
            }
            expLocation.push_back(expression[i]);
        }
        else{
            number += expression[i];
        }
    }
    
    num.push_back(stoi(number));
    sort(exp.begin(), exp.end());
    
    do{
        vector<long long> tmpNum = num;
        vector<char> tmpLocation = expLocation;
        
        for(int i=0; i<exp.size(); i++){
            for(int j=0; j<tmpLocation.size(); j++){
                if(exp[i] == tmpLocation[j]){
                    if(tmpLocation[j] == '+'){
                        tmpNum[j] = tmpNum[j] + tmpNum[j+1];
                    }
                    else if(tmpLocation[j] == '-'){
                        tmpNum[j] = tmpNum[j] - tmpNum[j+1];
                    }
                    else if(tmpLocation[j] == '*'){
                        tmpNum[j] = tmpNum[j] * tmpNum[j+1];
                    }
                    
                    tmpNum.erase(tmpNum.begin() + j+1);
                    tmpLocation.erase(tmpLocation.begin() + j);
                    j--;
                }
            }
        }
        if(answer<abs(tmpNum[0])){
            answer = abs(tmpNum[0]);
        }
    }
    while(next_permutation(exp.begin(), exp.end()));
    
    return answer;
}
