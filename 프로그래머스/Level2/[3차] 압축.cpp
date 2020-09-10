#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    
    int count = 1;
    int maxSize = 27;
    
    char capital = 'A';
    for(int i=1; i<=26; i++){
        string dicWord = "";
        dicWord += capital;
        dic[dicWord] = i;
        capital ++;
    }
    
    while(1){
        string w = msg.substr(0, count);
        string c = msg.substr(count, 1);
        string wc = w + c;
        map<string, int>::iterator findW = dic.find(w);
        map<string, int>::iterator findC = dic.find(c);
        map<string, int>::iterator findWC = dic.find(wc);
        
        if(findW != dic.end()){
            if(findWC != dic.end()){
                if(count < msg.size()) count++;
            }
            else{
                answer.push_back(findW -> second);
                dic.insert(make_pair(wc, maxSize));
                maxSize++;
                msg.erase(0, count);
                count = 1;
            }
        }
        
        
        if(c == "\0"){
            answer.push_back(findW->second);
            break;
        }
    }

    
    return answer;
}
