#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int i=0;
    vector <int> arr;
    
    for(int j=0; j<dartResult.length(); j++){
        
        if(dartResult[j]=='D'){
            arr[i-1] *= arr[i-1];
        }
        else if(dartResult[j]=='T'){
            arr[i-1] = arr[i-1]*arr[i-1]*arr[i-1];
        }
        else if(dartResult[j]=='S'){
            
        }
        else if(dartResult[j]=='*'){
            arr[i-1] *= 2;
            if(i>1){
                arr[i-2] *= 2;
            }
        }
        else if(dartResult[j]=='#'){
            arr[i-1] = arr[i-1] * -1;
        }
        else{
            if(dartResult[j+1]=='0'){
                arr.push_back(10);
                j++;
            }
            else
                arr.push_back(dartResult[j]-'0');
            i++;
        }
            
    }
    
        
    for(int i=0; i< arr.size(); i++){
        answer += arr[i];
    }
    
    return answer;
}
