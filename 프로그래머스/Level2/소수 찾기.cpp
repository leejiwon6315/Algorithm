#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool *primeArray;

void Eratos(int num){
    primeArray = new bool[num+1];
    
    primeArray[0] = false;
    primeArray[1] = false;
    
    for(int i=2; i<=num; i++) primeArray[i] = true;

    for(int i=2; i*i<=num; i++){
        if(primeArray[i])
            for(int j=i*i; j<=num; j+=i) primeArray[j] = false;

    }
}

bool includedNum(int num, string str){
    string stringNum = to_string(num);
    for(int i=0; i<stringNum.size(); i++){
        int flag = false;
        
        for(int j=0; j<str.size(); j++){
            if(stringNum.at(i) == str.at(j)){
                flag = true;
                str.at(j) = ' ';
                break;
            }
        }
        if(!flag) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    int maxNum = stoi(numbers);
    
    Eratos(maxNum);
    for(int i=0; i<=maxNum; i++){
        if(primeArray[i] && includedNum(i, numbers)) answer ++;
    }
    
    return answer;
}
