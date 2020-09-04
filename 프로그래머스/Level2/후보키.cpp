#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check_min(vector<int> &keys, int bit){
    for(int i=0; i<keys.size(); i++){
        if((keys[i] & bit) == keys[i]) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    vector<int> keys;
    int tupleSize = relation.size();
    int columnSize = relation[0].size();
    
    for(int bit = 1; bit < (1 << columnSize); bit++){
        if(!check_min(keys, bit)) continue;
    
        unordered_set<string> set;    // key 값과 비교해서 요소가 존재하는 지 판별
        
        for(int i=0; i<tupleSize; i++){
            string key;
            for(int j=0; j<columnSize; j++){
                if(bit & (1 << j)) key += relation[i][j] + ' ';
            }
            set.insert(key);
        }
        
        if(set.size() == tupleSize){
            keys.push_back(bit);
            answer ++;
        }
    }
    return answer;
}
