#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, char>> tmp;
    map<string, string> chatMap;
    
    for(int i=0; i<record.size(); i++){
        if(record[i][0] == 'E'){
            string id = "";
            int j;
            for(j=6; record[i][j]!=' '; j++){
                id += record[i][j];
            }
            
            string nick = "";
            for(j=(j+1); j<record[i].size(); j++){
                nick += record[i][j];
            }
            
            chatMap[id] = nick;
            tmp.push_back({id, 'E'});
            
        }
        
        else if(record[i][0] == 'L'){
            string id = "";
            int j;
            for(j=6; j<record[i].size(); j++){
                id += record[i][j];
            }
            
            tmp.push_back({id, 'L'});
            
        }
        else if(record[i][0] == 'C'){
            string id = "";
            int j;
            for(j=7; record[i][j]!=' '; j++){
                id += record[i][j];
            }
            
            string nick = "";
            for(j=(j+1); j<record[i].size(); j++){
                nick += record[i][j];
            }
            chatMap[id] = nick;
        }
    }
    
    for(int i=0; i<tmp.size(); i++){
        string resultRecord = "";
        resultRecord += chatMap[tmp[i].first];
        if(tmp[i].second == 'E'){
            resultRecord += "님이 들어왔습니다.";
        }
        else if(tmp[i].second == 'L'){
            resultRecord += "님이 나갔습니다.";
        }
        
        answer.push_back(resultRecord);
    }
    return answer;
}
