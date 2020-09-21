#include <string>
#include <vector>
#define difer 0.001
#define ABS(x) x<0 ? -x : x

using namespace std;

vector<string> splitStr(string str, char space = ' '){
    vector<string> output;
    
    int index=0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == space){
            output.push_back(str.substr(index, i-index));
            index = i+1;
        }
    }
    if(index != str.size()){
        output.push_back(str.substr(index, str.size()-index));
    }
    
    return output;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<double>> timeList;
    
    for(int i=0; i<lines.size(); i++){
        vector<string> tmp = splitStr(lines[i]);
        vector<string> splitedTime = splitStr(tmp[1], ':');
        
        double endTime = stod(splitedTime[0])*3600 + stod(splitedTime[1])*60 + stod(splitedTime[2]);
        double opTime = stod(splitStr(tmp[2], 's')[0]);
        
        timeList.push_back({(endTime - opTime + 0.001), endTime});
    }
    
    for(int i=0; i<timeList.size(); i++){
        double begin = timeList[i][1];
        double end = begin + 0.999;
        
        int tmp = 0;
        for(int j=i; j<timeList.size(); j++){
            if(timeList[j][1] - begin >= difer && ABS(timeList[j][0] - end) <=difer){
                tmp ++;
            }
        }
        
        if(answer < tmp) answer = tmp;
    }
    
    return answer;
}
