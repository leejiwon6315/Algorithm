#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> chcheArr;
        
    if(!cacheSize) return cities.size()*5;
    
    for(int i=0; i<cities.size(); i++)
         transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    
    for(int i=0; i<cities.size(); i++){
        bool flag = false;
        
        if(chcheArr.size() < cacheSize){
            for(int j=0; j<chcheArr.size(); j++){
                if(cities[i] == chcheArr[j]){
                    chcheArr.erase(chcheArr.begin()+j);
                    chcheArr.push_back(cities[i]);
                    answer ++;
                    flag = true;
                    break;
                }
            }
            
            if(flag == false){
                chcheArr.push_back(cities[i]);
                answer += 5;
            }
        }
        else{
            for(int j=0; j<cacheSize; j++){
                if(cities[i] == chcheArr[j]){
                    answer ++;
                    chcheArr.erase(chcheArr.begin()+j);
                    chcheArr.push_back(cities[i]);
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                chcheArr.erase(chcheArr.begin()+0);
                chcheArr.push_back(cities[i]);
                answer += 5;                
            }

        }
 
    }
    return answer;
}
