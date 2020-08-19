#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends;
    
    string kakaoFriends = "ACFJMNRT";
    
    for(int i=0; i<kakaoFriends.size(); i++){
        friends.push_back(kakaoFriends[i]);
    }
    
    do{
        bool isOk = true;
    
        for(int i=0; i<data.size(); i++){
            char left = data[i][0];
            char right = data[i][2];
            char sign = data[i][3];
            int dist = data[i][4] - '0';
            
            int left_idx, right_idx;
            
            for(int j=0; j<8; j++){
                if(friends[j] == left) left_idx = j;
                if(friends[j] == right) right_idx = j;
            }
            
            switch(sign){
            case '=':
                    if(abs(left_idx - right_idx)-1 != dist) isOk = false;
                    break;
            case '<':
                    if(abs(left_idx - right_idx)-1 >= dist) isOk = false;
                    break;
            case '>':
                    if(abs(left_idx - right_idx)-1 <= dist) isOk = false;
                    break;        
            }
        if(!isOk) break;     
        }
    if(isOk) answer ++;   
    
    }while(next_permutation(friends.begin(), friends.end()));
    return answer;
}
