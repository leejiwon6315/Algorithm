#include <string>
#include <vector>

using namespace std;

vector<string> splitStr(string str, char ch){
    vector<string> result;
    int count = 0;
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == ch){
            result.push_back(str.substr(count, i-count));
            count = i+1;
        }
    }
    result.push_back(str.substr(count, str.size()-1));
    return result;
}

vector<string> splitCode(string str){
    vector<string> musicCode;
    
    for(int i=0; i<str.size(); i++){
        
        if(str[i+1] == '#'){
            string tmp ="";
            tmp += (str[i] + str[i+1]);
            musicCode.push_back(tmp);
            i++;
        }
        else{
            string tmp ="";
            tmp += str[i];
            musicCode.push_back(tmp);
        }  
    }
    return musicCode;
}

bool sameCode(vector<string> mCode ,vector<string> infoCode){
    
    for(int i=0; i<infoCode.size(); i++){
        if(infoCode[i] != mCode[0]) continue;
        bool tmp = false;
        int k=i;
        
        for(int j=0; j<mCode.size(); j++){
            if(infoCode[k] != mCode[j]){
                tmp = false;
                break;
            }
            else{
                tmp = true;
                k++;
            } 
        }
        if(tmp) return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int longestSong = 0;
    for(int i=0; i<musicinfos.size(); i++){
        vector<string> notComma = splitStr(musicinfos[i], ',');
        vector<string> startTime = splitStr(notComma[0], ':');
        vector<string> endTime = splitStr(notComma[1], ':');
        vector<string> musicInfoCode = splitCode(notComma[3]);
        
        int playTime = (stoi(endTime[0]) - stoi(startTime[0]))*60 + (stoi(endTime[1]) - stoi(startTime[1]));
        
        if(playTime < 0) playTime += 1440;
        if(longestSong > playTime) continue;
        if(longestSong == playTime && answer != "(None)") continue;
        
        vector<string> playedMusic;
        for(int j=0; j<playTime; j++){
            int index = j%musicInfoCode.size();
            playedMusic.push_back(musicInfoCode[index]);
        }
        
        if(sameCode(splitCode(m), playedMusic)){
            longestSong = playTime;
            answer = notComma[2];
        }
    }
    
    return answer;
}
