#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> tmp;
    
    for(int i=0; i<numbers.size()-1; i++){
        for(int j=i+1; j<numbers.size(); j++){
            tmp.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(tmp.begin(), tmp.end());
    
    for(int i=0; i<tmp.size(); i++){
        answer.push_back(tmp[i]);
        while(tmp[i] == tmp[i+1]){ 
            i++;
        }
    }
    
    return answer;
}
