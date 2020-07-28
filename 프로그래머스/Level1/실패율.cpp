#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool gg(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> sil;

    for(int i=1; i<=N; i++){
        
        int nocl = 0;
        int dodal = 0;
        
        for(int j=0; j<stages.size(); j++){
            
            if(i == stages[j]) nocl ++;
            if(i <= stages[j]) dodal ++;  
            
        }
        
        if(dodal == 0 || nocl == 0) sil.push_back({i,0});
        else sil.push_back({i, (double)nocl/dodal});
        
    }
    
    sort(sil.begin(), sil.end(), gg);
    
    for(int i=0; i<sil.size(); i++){
        answer.push_back(sil[i].first);
    }
    
    return answer;
}
