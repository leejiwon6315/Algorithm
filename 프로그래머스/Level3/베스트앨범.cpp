#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays){
    vector<int> answer;
    map<string, int> songList;
    map<string, map<int, int>> songGenres;
    
    for(int i=0; i<plays.size(); i++){
        songList[genres[i]] += plays[i];
        songGenres[genres[i]][i] = plays[i];
    }
    
    while(songList.size()){
        int max = 0;
        string maxGenre = "";
        
        for(auto mu : songList){
            if(max < mu.second){
                max = mu.second;
                maxGenre = mu.first;
            }
        }
        
        for(int i=0; i<2; i++){
            int max2 = 0, index = -1;
            
            for(auto mu : songGenres[maxGenre]){
                if(max2 < mu.second){
                    max2 = mu.second;
                    index = mu.first;
                }
            }
            
            if(index == -1) break;
            answer.push_back(index);
            songGenres[maxGenre].erase(index);
        }
        songList.erase(maxGenre);
    }
    
        
    return answer;
}
